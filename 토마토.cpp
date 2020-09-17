// Lim Hwangyu
// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
using namespace std;
int tomato[1005][1005];
const int dirY[] = { -1, 1, 0, 0 }; // »óÇÏÁÂ¿ì
const int dirX[] = { 0, 0, -1, 1 };
int main() {
	int n, m;
	cin >> n >> m;
	queue<int> qx, qy, qd;
	int check_cnt = 0;
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == 0 || i == m + 1 || j == 0 || j == n + 1) {
				tomato[i][j] = -1;
				continue;
			}
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				qy.push(i);
				qx.push(j);
				qd.push(0);
			}
			else if (tomato[i][j] == 0) {
				check_cnt++;
			}
		}
	}

	int cnt = 0;
	int max = 0;
	while (!qx.empty()) {
		int y = qy.front(), x = qx.front(), d = qd.front();
		qy.pop(); qx.pop(); qd.pop();
		if (max < d) max = d;
		for (int i = 0; i < 4; i++) {
			int next_y = y + dirY[i];
			int next_x = x + dirX[i];
			if (tomato[next_y][next_x] == 0) {
				tomato[next_y][next_x] = d+1;
				qy.push(next_y);
				qx.push(next_x);
				qd.push(d + 1);
				cnt++;
			}
		}
	}
	int answer;
	if (check_cnt == cnt) answer = max;
	else answer = -1;
	cout << answer << endl;
	return 0;
}