// Lim Hwangyu
// http://codeforces.com/problemset/problem/230/B
#include <iostream>
#include <cmath>
#include <map>
#define MAX 1000 * 1000 * 1000 * 1000
using namespace std;

int main() {
	int n; __int64 a[110000];
	map<__int64, bool> t_primes;
	cin >> n; for (int i = 0; i < n; i++) cin >> a[i];

	for (__int64 i = 2; i < 1000 * 1000; i++) {
		bool prime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i%j == 0) {
				prime = false;
				break;
			}
		}
		if (prime) t_primes[i*i] = true;
	}

	for (int i = 0; i < n; i++) {
		if (t_primes[a[i]]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
