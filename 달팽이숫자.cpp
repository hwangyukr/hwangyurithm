// Lim Hwangyu
// https://swexpertacademy.com/main/code/problem/problemList.do?problemTitle=1954&orderBy=FIRST_REG_DATETIME&select-1=&pageSize=10&pageIndex=1#none

#include <iostream>
using namespace std;
int dirX[4] = { 1,0,-1,0 }, dirY[4] = { 0,1,0,-1 };
int map[10][10];
int collision(int n, int px, int py) {
	if (px < 0) return 1;
	if (py < 0) return 1;
	if (px >= n) return 1;
	if (py >= n) return 1;
	if (map[py][px] > -1) return 1;
	return 0;
}
void snail(int n) {
	int x = 0, y = 0, d = 0; for (int i = 0; i < 10; i++) fill_n(map[i], 10, -1);
	for (int i = 0; i < n*n; i++) {
		map[y][x] = i + 1;
		int px = x + dirX[d];
		int py = y + dirY[d];
		if (collision(n, px, py)) {
			d++; d %= 4;
			x += dirX[d];
			y += dirY[d];
		}
		else {
			x = px; y = py;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j]; if (j < n - 1)  cout << " ";
		}
		cout << endl;
	}
}
int main() {
	int c; cin >> c;
	int n[10]; for (int i = 0; i < c; i++) cin >> n[i];
	for (int i = 0; i < c; i++) {
		cout << '#' << i + 1 << endl;
		snail(n[i]);
	}
	return 0;
}
