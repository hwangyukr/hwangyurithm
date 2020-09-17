#include <iostream>
using namespace std;

int main(void) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		int n, m, answer = 0;
		cin >> n >> m;
		int a[20][20];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				int sum = 0;
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < m; jj++) {
						sum += a[i + ii][j + jj];
					}
				}
				if (answer < sum) {
					answer = sum;
				}
			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}