// Lim Hwangyu
// https://www.acmicpc.net/problem/2156
#include <iostream>
using namespace std;
int n, wine[10000], cache[10000][3], max = 0;
int drink(int k, int combo) {
	if (k >= n) return 0;
	if (cache[k][combo] >= 0) return cache[k][combo];
	if (combo > 1) {
		return cache[k][combo] = drink(k + 1, 0);
	}
	int l = wine[k] + drink(k + 1, combo + 1);
	int r = drink(k + 1, 0);
	int node = (l > r ? l : r);
	cache[k][combo] = node;
	return node;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
		fill_n(cache[i], 3, -1);
	}
	cout << drink(0, 0) << endl;
	return 0;
}
