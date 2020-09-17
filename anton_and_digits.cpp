// Lim Hwangyu
// http://codeforces.com/problemset/problem/734/B

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int digits[4];
int search(int c256, int c32, int d2, int d3, int d5, int d6) {
	vector<int> vec;
	if (d2 > 0 && d5 > 0 && d6 > 0) {
		vector<int> t = { d2,d5,d6 };
		int min = *min_element(t.begin(), t.end());
		vec.push_back(search(c256 + min, c32, d2 - min, d3, d5 - min, d6 - min));
	}
	else if (d3 > 0 && d2 > 0) {
		vector<int> t = { d3,d2 };
		int min = *min_element(t.begin(), t.end());
		vec.push_back(search(c256, c32 + min, d2 - min, d3 - min, d5, d6));
	}
	vec.push_back(c256 * 256 + c32 * 32);
	int biggest = *max_element(vec.begin(), vec.end());
	return biggest;
}

int main() {
	for (int i = 0; i < 4; i++) cin >> digits[i];
	cout << search(0, 0, digits[0], digits[1], digits[2], digits[3]) << endl;
	return 0;
}