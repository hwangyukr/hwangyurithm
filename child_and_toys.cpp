// Lim Hwangyu
// https://codeforces.com/problemset/problem/437/C
#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int n, m;
	int node[1000];
	int node_order[1000];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> node[i];
		node_order[i] = i;
	}
	int sum = 0;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		sum += min(node[n1 - 1], node[n2 - 1]);
	}

	cout << sum << endl;
	return 0;
}