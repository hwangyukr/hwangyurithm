#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long int INT;
typedef vector<vector<INT>> MAP;
#define DEVIDOR 10000000

INT poly(int n, int k, MAP& cache) {
	if (n <= 0) return 1;
	INT& ret = cache[n][k];
	if (ret > 0) return ret;

	for (int i = 1; i <= n; i++) {
		int movable = (i + k - 1);
		if (k == 0) movable = 1;
		ret += (poly(n - i, i, cache) * movable + DEVIDOR) % DEVIDOR;
	}
	return ret;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n; cin >> n;
		MAP cache(n+1, vector<INT>(n+1, 0));
		INT res = poly(n, 0, cache);
		cout << res % DEVIDOR << endl;
	}
	return 0;
}