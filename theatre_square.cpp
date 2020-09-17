// Lim Hwangyu
// https://codeforces.com/problemset/problem/1/A

#include <iostream>
using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m >> a;
	__int64 w = (n / a) + int(n%a != 0);
	__int64 h = (m / a) + int(m%a != 0);
	cout << w * h << endl;
	return 0;
}
