// Lim Hwangyu
// https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <string>
using namespace std;

int main() {
	int c;
	string n[100];
	cin >> c;
	for (int i = 0; i < c; i++) cin >> n[i];
	for (int i = 0; i < c; i++) {
		string str = n[i];
		if (n[i].length() <= 10) {
			cout << str << endl;
			continue;
		}
		int l = str.length();
		cout << str[0] << l - 2 << str[l - 1] << endl;
	}
	return 0;
}
