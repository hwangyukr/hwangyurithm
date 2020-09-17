#include <iostream>
#include <string>
using namespace std;

// 60min 쓸데없이 오래걸림

string reverse_tree(string input, int k, int n, int &pos) {
	if (input[k] == 'w') {
		pos = 1;
		return string("w");
	}
	if (input[k] == 'b') {
		pos = 1;
		return string("b");
	}
	if (input[k] == 'x') {
		int p = 1;
		int temp = 0;
		string ch1 = reverse_tree(input, k + p, n, temp);
		p += temp;
		string ch2 = reverse_tree(input, k + p, n, temp);
		p += temp;
		string ch3 = reverse_tree(input, k + p, n, temp);
		p += temp;
		string ch4 = reverse_tree(input, k + p, n, temp);
		p += temp;
		pos = p;
		return "x" + ch3 + ch4 + ch1 + ch2;
	}
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		string input;
		cin >> input;
		int n = input.length();

		string res; int t=0;
		res = reverse_tree(input, 0, n, t);
		cout << res << endl;
	}
	return 0;
}