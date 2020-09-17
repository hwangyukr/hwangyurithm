#include <iostream>
#include <vector>
using namespace std;
typedef long long int INT;
// 10min

#define DEVIDOR 1000000007
INT tiling2(int n, int p, vector<INT> &cache) {
	if (p >= n - 1) return 1;
	if (p == n - 2) return 2;
	if (cache[p] > 0) return cache[p];
	INT& ret = cache[p];
	ret = tiling2(n, p + 1, cache);
	ret += tiling2(n, p + 2, cache);
	return ret % DEVIDOR;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n; cin >> n;
		vector<INT> cache(n, 0);
		INT res = tiling2(n, 0, cache);
		cout << res << endl;
	}
	return 0;
}