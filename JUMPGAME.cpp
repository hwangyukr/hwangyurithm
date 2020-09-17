#include <iostream>
using namespace std;

int map[101][101];
int cache[101][101];
int n;

// 10min
int jump(int y, int x) {
	if (y > n - 1 || x > n - 1) return 0;
	int& ret = cache[y][x];
	if (y == n - 1 && x == n - 1) return (ret=1);
	if (ret != -1) return ret;

	int amount = map[y][x];
	int avail = 0;
	avail += jump(y + amount, x);
	avail += jump(y, x + amount);

	return (ret = (avail > 0));
}

int main() {
	int T; cin >> T;
	for (int test_num = 1; test_num <= T; test_num++) {
		// test_num ++ 대신 T++ 해버렸네... 꼭 이상한실수함
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				cache[i][j] = -1;
			}
		}

		int available = jump(0, 0);
		if (available == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}