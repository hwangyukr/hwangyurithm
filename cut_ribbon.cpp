// Lim Hwangyu
// http://codeforces.com/problemset/problem/189/A
#include <iostream>
using namespace std;
int p[4001];
int n, a, b, c;

int main() {
	cin >> n >> a >> b >> c;
	int t[3]; t[0] = a; t[1] = b; t[2] = c;
	p[a] = p[b] = p[c] = 1;
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < 3; j++) {
			if (i >= t[j] && p[i - t[j]] > 0) {
				int _t = p[i - t[j]] + 1;
				if (max < _t) max = _t;
			}
		}
		if(p[i] < max) p[i] = max;
	}
	cout << p[n] << endl;
	return 0;
}
