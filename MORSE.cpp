// 조합 nCr 구현 못해서 한시간 헤맴
// 나머지는 약 45분 소요
// 이항계수 구할땐 !!파스칼의삼각형!! 이용하자

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 2000000000

typedef long long int INT;

/*
*** 잘못된 combination 구현 (overflow) ***

INT combination(int big, int small) {
	INT res = 1;
	int b = big;
	for (int i = 1; i <= small; i++) {
		INT prev_res = res;
		res *= b;
		if (res < prev_res) return MAX; // check overflow
		b--;
		res /= i;
	}
	return res;
}
*/

INT comb[201][201];

void prev_calc() {
	for (int i = 0; i <= 200; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = min((INT)MAX, comb[i - 1][j - 1] + comb[i - 1][j]);
		}
	}
}

string solve(int n, int m, INT k) {
	string ret = "";
	if (n == 0) return string(m, 'o'); // "oooooo...(n개)"
	// if (m == 0) return string(n, '-'); // m==0이 안들어온다는 보장이 있나?

	INT skip = comb[n + m - 1][m];

	if (k >= skip) {
		return 'o' + solve(n, m - 1, k - skip);
	}
	else {
		return '-' + solve(n - 1, m, k);
	}
}

int main() {
	int T; cin >> T;
	prev_calc();

	for (int test_case = 1; test_case <= T; test_case++) {
		int n, m, k; cin >> n >> m >> k;
		cout << solve(n, m, (INT)k-1) << endl; 
	}

	return 0;
}

