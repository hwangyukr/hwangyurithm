// Lim Hwangyu
// https://algospot.com/judge/problem/read/POLY
#include <iostream>
using namespace std;
#define M 10000000 // Moding
int memoi[101][101]; // Memoization of DFS
// pn : number of parent block
// n : number of block
int f(int pn, int n) { 
	if (memoi[pn][n] >= 0) return memoi[pn][n];
	int c = pn + n - 1;
	for (int i = 1; i < n; i++) {
		c += f(i, n - i) * (i + pn - 1); c %= M;
	}
	memoi[pn][n] = c;
	return c;
}

int root(int n) {
	int c = 1;
	for (int i = 1; i < n; i++) {
		c += f(i, n - i); c %= M;
	}
	return c;
}

int main() {
	int c, n[50];
	cin >> c;
	for (int i = 0; i < 101; i++) fill_n(memoi[i], 101, -1);
	for (int i = 0; i < c; i++) cin >> n[i];
	for (int i = 0; i < c; i++) cout << root(n[i]) % M << endl;
	return 0;
}
