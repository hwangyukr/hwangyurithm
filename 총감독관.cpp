// Lim Hwangyu
// https://www.acmicpc.net/problem/13458
#include <iostream>
#include <list>
using namespace std;
list<int> li;
int main() {
	int n, b, c;
	long long sum = 0;
	cin >> n;	
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		li.push_back(m);
	}
	cin >> b >> c;
	for (list<int>::iterator iter = li.begin(); iter != li.end(); iter++) {
		int acc = (*iter) - b;
		if (acc < 0) acc = 0;
		if (acc % c != 0) acc = acc / c + 1;
		else acc = acc / c;
		sum += 1 + acc;
	}

	cout << sum << endl;
	return 0;
}
