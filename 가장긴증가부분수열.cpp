// Lim Hwangyu
// https://algospot.com/judge/problem/read/LIS

#include <iostream>
using namespace std;
int process(int n, int *a) {
	int maxLength = 0;
	int cnt[500];
	for (int i = 0; i < n; i++) {
		int max = 0; cnt[i] = 1;
		for (int j = i - 1; j >= 0; j--) if (a[i] > a[j] && max < cnt[j]) max = cnt[j];
		cnt[i] += max; if (maxLength < cnt[i]) maxLength = cnt[i];
	}
	return maxLength;
}
int main() {
	int c, n[50], a[50][500];
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n[i]; for (int j = 0; j < n[i]; j++) cin >> a[i][j];
	}
	for (int i = 0; i < c; i++) cout << process(n[i], a[i]) << endl;
	return 0;
}
