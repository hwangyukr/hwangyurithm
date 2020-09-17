// Lim Hwangyu
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GKs06AU0DFAXB&categoryId=AV7GKs06AU0DFAXB&categoryType=CODE

#include <iostream>
using namespace std;

int n, a[11][11];

int queen(int y) {
	if (y > n - 1) {
		/* // 결과 출력하는 코드
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
		cout << endl;
		*/
		return 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool b = false;
		for (int j = 1; j <= y; j++) {
			if (y >= j && a[y - j][i] != 0) b = true;
			if (y >= j && i >= j && a[y - j][i - j] != 0) b = true;
			if (y >= j && i + j < n && a[y - j][i + j] != 0) b = true;
		}
		if (b) continue;
		a[y][i] = 1;
		cnt += queen(y + 1);
		a[y][i] = 0;
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		for (int i = 0; i < n; i++) fill_n(a[i], n, 0);
		cout << "#" << test_case << " " << queen(0) << endl;
	}
	return 0;
}
