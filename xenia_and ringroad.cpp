// Lim Hwangyu
// http://codeforces.com/problemset/problem/339/B

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int dist(int a, int b) {
	int l = b - a;
	if (l < 0) l += n;
	return l;
}

int main() {
	int m; cin >> n >> m;
	int a[100000];
	int prev = 1;
	__int64 w = 0;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		int d = dist(prev, t);
		w += d;
		prev = t;
	}

	cout << w << endl;
	return 0;
}
