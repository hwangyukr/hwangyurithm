#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100000000

// 60min
int SWITCH[10][5] = {
	{0,1,2,-1,-1},
	{3,7,9,11,-1},
	{4,10,14,15,-1},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15,-1},
	{3,14,15,-1,-1},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};
int SWITCH_CNT[10] = {3, 4, 4, 5, 5, 4, 3, 5, 5, 5};

void do_switch(int* clocks, int switch_num) {
	for (int j = 0; j < SWITCH_CNT[switch_num]; j++) {
		int& clock = clocks[SWITCH[switch_num][j]];
		clock = clock + 1;
		if (clock > 3) clock = 0;
	}
}

int find_min_try(int *clocks, int switch_num, int total_cnt, int min) {
	if (total_cnt > min) return MAX;
	bool sync = true;
	for (int i = 0; i < 16; i++) {
		if (clocks[i] != 0) sync = false;
	}
	if (sync == true) {
		return total_cnt;
	}
	if (switch_num >= 10) {
		return MAX;
	}

	int t_clocks[16];
	memcpy(t_clocks, clocks, 16 * 4);
	for (int i = 0; i <= 3; i++) {
		if(i>0) do_switch(t_clocks, switch_num);
		int ret = find_min_try(t_clocks, switch_num+1, total_cnt+i, min);
		if (ret < min) min = ret;
	}

	return min;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int clocks[16];
		for (int i = 0; i < 16; i++) {
			int time;
			cin >> time;
			time = (time / 3) % 4;
			clocks[i] = time;
		}
		int res = find_min_try(clocks, 0, 0, MAX);
		if (res == MAX) res = -1;
		// 경우가 없을 땐 -1 출력인걸 까먹고 MAX그대로 출력하다 10분날림
		cout << res << endl;
	}
	return 0;
}
