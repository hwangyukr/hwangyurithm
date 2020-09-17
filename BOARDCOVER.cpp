#include <iostream>
using namespace std;

// 0430 80분

int find_case(int mat[][20], int y, int x, int py, int px, int h, int w) { // py, px는 이전좌표
	int ret = 0;
	if (px >= 0 && mat[py][px] == 0) return 0;
	// 지나 온 좌표가 0이면 cut-off

	bool finish = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (mat[i][j] == 0) finish = false;
		}
	}
	if (finish) {
		return 1;
	}

	if (y > h - 2) return 0;

	int &b11 = mat[y][x];
	int &b12 = mat[y][x+1];
	int &b21 = mat[y+1][x];
	int &b22 = mat[y+1][x+1];

	int nX = x + 1;
	int nY = y;
	if (nX > w - 2) {
		nX = 0;
		nY = y + 1;
	}

	if (b12 == 0 && b21 == 0 && b22 == 0) {
		b12 = b21 = b22 = 2;
		ret += find_case(mat, nY, nX, y, x, h, w);
		b12 = b21 = b22 = 0;
	}
	if (b11 == 0 && b21 == 0 && b22 == 0) {
		b11 = b21 = b22 = 2;
		ret += find_case(mat, nY, nX, y, x, h, w);
		b11 = b21 = b22 = 0;
	}
	if (b11 == 0 && b12 == 0 && b22 == 0) {
		b11 = b12 = b22 = 2;
		ret += find_case(mat, nY, nX, y, x, h, w);
		b11 = b12 = b22 = 0;
	}
	if (b11 == 0 && b12 == 0 && b21 == 0) {
		b11 = b12 = b21 = 2;
		ret += find_case(mat, nY, nX, y, x, h, w);
		b11 = b12 = b21 = 0;
	}
	ret += find_case(mat, nY, nX, y, x, h, w);
	return ret;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int h, w;
		cin >> h >> w;
		int mat[20][20];
		for (int i = 0; i < h; i++) {
			char temp[30];
			cin >> temp;
			for (int j = 0; j < w; j++) {
				if (temp[j] == '#') mat[i][j] = 1; // 1 is black
				else mat[i][j] = 0;
			}
		}
		int res = find_case(mat, 0, 0, -1, -1, h, w);
		cout << res << endl;
	}
}