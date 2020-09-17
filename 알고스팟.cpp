#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INFINITE 100000

int a[100][100];
int cache[100][100];
int n, m;
int mini = INFINITE;

queue<int> qx, qy, qc;

const int dirY[4] = {-1, 1, 0, 0};
const int dirX[4] = {0, 0, -1, 1};

int main() {
	cin >> m >> n;
	string str[100];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 0; j < m; j++) {
			a[i][j] = str[i][j] - '0';
			cache[i][j] = INFINITE;
		}
	}

	qx.push(0);
	qy.push(0);
	qc.push(0);
	while (!qx.empty()) {
		int tx = qx.front();
		int ty = qy.front();
		int tc = qc.front();
		// q.back() À¸·Î ½è´Ù°¡  ¾öÃ» Çì¸Ì´Ù.

		qx.pop();
		qy.pop();
		qc.pop();
		cache[ty][tx] = tc + a[ty][tx];

		if (ty == n - 1 && tx == m - 1) {
			if (mini > tc) mini = tc;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = tx + dirX[i];
			int ny = ty + dirY[i];
			if (ny < 0 || nx < 0 || ny > n - 1 || nx > m - 1) {
				continue;
			}
			int nc = tc + a[ty][tx];

			if (cache[ny][nx] > nc) {
				qx.push(nx);
				qy.push(ny);
				qc.push(nc);
				cache[ny][nx] = nc;
			}
		}
	}
	cout << mini << endl;
	return 0;
}
