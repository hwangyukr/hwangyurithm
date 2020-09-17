// Lim Hwangyu
// https://algospot.com/judge/problem/read/FESTIVAL

#include <iostream>
using namespace std;
// dp(길이, 위치)
int dp[1000][1000];

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		int n, m, cost[1000];
		cin >> n >> m;
		double min_avg = 1000001;
		for (int i = 0; i < n; i++) {
			fill(dp[i], dp[i] + n - 1, 0);
			cin >> cost[i];
			dp[0][i] = cost[i]; // 길이가 1에 해당하는 원소 채우기
			// 입력이 한개일 때 예외처리
			if (m == 1 && min_avg > cost[i]) min_avg = cost[i];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				dp[i][j] = dp[i - 1][j] + cost[i + j];
				if (i + 1 >= m) {
					double avg = dp[i][j] / double(i + 1);
					if (min_avg > avg) min_avg = avg;
				}
			}
		}

		// ***** 실수를 출력하는 자리수 설정하기  ******
		cout.setf(ios::fixed);
		cout.precision(8);
		cout << min_avg << endl;
		continue;
	}
	return 0;
}
