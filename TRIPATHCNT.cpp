#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int>> MAT;
void input(MAT &mat, int);

// 35min
int tripathcnt(MAT& mat, int n, int y, int x, int& cnt, MAT& cache_len, MAT& cache_cnt) {
	cnt = 0;
	if (y == n - 1) {
		cnt = 1;
		return mat[y][x];
	}

	int& ret = cache_len[y][x];
	if (ret > 0) {
		cnt = cache_cnt[y][x];
		return ret;
	}

	int maxCnt = 0;
	int nCnt1, nCnt2;
	int child1 = tripathcnt(mat, n, y + 1, x, nCnt1, cache_len, cache_cnt);
	int child2 = tripathcnt(mat, n, y + 1, x + 1, nCnt2, cache_len, cache_cnt);

	ret = mat[y][x];
	if (child1 == child2) {
		ret += child1;
		cnt = nCnt1 + nCnt2;
	}
	else if (child1 > child2) {
		ret += child1;
		cnt = nCnt1;
	}
	else {
		ret += child2;
		cnt = nCnt2;
	}
	cache_cnt[y][x] = cnt;
	return ret;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n; cin >> n;
		MAT mat(n, vector<int>(n, 0));
		MAT cache_len(n, vector<int>(n, 0));
		MAT cache_cnt(n,vector<int>(n,0));
		input(mat, n);
		int cnt;
		int dummy = tripathcnt(mat, n, 0, 0, cnt, cache_len, cache_cnt);
		cout << cnt << endl;
	}
	return 0;
}

void input(MAT& mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> mat[i][j];
		}
	}
}
