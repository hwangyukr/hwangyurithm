// Lim Hwangyu
// https://codeforces.com/problemset/problem/118/A

#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	cin >> n;
	char vowel[6] = { 'a','e','o' ,'u' ,'i', 'y' };

	for (int i = 0; i < n.size(); i++) {
		if (n[i] >= 'A' && n[i] <= 'Z') {
			n[i] -= 'A';
			n[i] += 'a';
		}
	}


	for (int i = n.size(); i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (vowel[j] == n[i]) {
				n.erase(i, 1);
			}
		}
	}

	for (int i = n.size()-1; i >= 0; i--) {
		n.insert(i, ".");
	}



	cout << n;
	return 0;
}
