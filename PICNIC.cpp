#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> MAT;

// 0430 35Ка

int get_friends_case(MAT &mat, int k, int n, vector<int> &chk) {
	int cnt = 0;
	if (k >= n) return 1;
	if(chk[k] == 1) return get_friends_case(mat, k + 1, n, chk);
	for (int i = 0; i < n; i++) {
		if (mat[k][i] == 1 && chk[i] == 0) {
			mat[k][i] = 2;
			mat[i][k] = 2;
			chk[i] = chk[k] = 1;
			cnt += get_friends_case(mat, k+1, n, chk);
			chk[i] = chk[k] = 0;
			mat[k][i] = 1;
			mat[i][k] = 1;
		}
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n, m;
		cin >> n >> m;
		MAT mat(n, vector<int>(n, 0));
		vector<int> chk(n, 0);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			mat[a][b] = mat[b][a] = 1;
		}
		int res = 0;
		res = get_friends_case(mat, 0, n, chk);
		cout << res << endl;
	}

	return 0;
}