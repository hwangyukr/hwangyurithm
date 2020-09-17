// Lim Hwangyu
// http://codeforces.com/contest/545/problem/C

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int n; cin >> n;

	if (n <= 2) {
		cout << n << endl;
		return 0;
	}

	int prev_p, prev_h; cin >> prev_p >> prev_h;
	int p, h; cin >> p >> h;
	int next_p, next_h;
	int cnt = 2; // 양끝은 무조건 쓰러짐 (i=0, i=n-1)
	for (int i = 1; i < n-1; i++) {
		cin >> next_p >> next_h;
		if (p - prev_p > h) { // 왼쪽으로 쓰러뜨리는거 가능하면 쓰러뜨리기
			cnt++;
		}
		else if (next_p - p > h) { // 오른쪽으로 쓰러뜨리는거 가능하면 쓰러뜨리기
			cnt++;
			p = p + h; // 오른쪽으로 쓰러진거 표시
		}
		prev_p = p;
		prev_h = h;
		p = next_p;
		h = next_h;
	}

	cout << cnt << endl;
	return 0;
}