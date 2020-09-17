#include <iostream>
#include <vector>
using namespace std;
// 20 min
// double출력할때  cout.precision 으로 오차범위 늘려야 함!

double snail(int n, int m, int y, int cnt, vector<vector<double>> &cache) {
	if (cnt > m) return 0;
	if (y > n - 1) return 1.0;
	double& ret = cache[y][cnt];
	if (ret >= 0) return ret;
	ret = 0.25 * snail(n, m, y + 1, cnt + 1, cache) + 0.75 * snail(n, m, y + 2, cnt + 1, cache);
	return ret;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n, m; cin >> n >> m;
		vector<vector<double>> cache(1001, vector<double>(1001, -1));
		double res = snail(n, m, 0, 0, cache);
		cout.precision(8);
		cout << res << endl;
	}
	return 0;
}
