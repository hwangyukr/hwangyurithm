// 4시간 이상, 답안 참고함

#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long int INT;
const int MAXN = 50;
string FX = "FX";

INT nFunc(INT level) { // 미리 배열에 계산해 놓으면 실행시간 절약 !
	if (level == 0) return 1;
	return nFunc(level-1) * 2 + 2;
}

char Func(string words, int n, INT &m) {

	if (n == 0) {
		// m < 5 인걸 어떻게 보장하지?
		return words[m];
	}

	for (int i = 0; i < words.size(); i++) {
		char iter = words[i];

		string expandor = "";
		if (iter == 'X') expandor = "X+YF";
		if (iter == 'Y') expandor = "FX-Y";
		if (iter == 'X' || iter == 'Y') {
			INT len = nFunc(n);
			if (m >= len) {
				m -= len;
				continue;
			}
			return Func(expandor, n - 1, m);
		}
		else {
			if (m > 0) m--;
			else return iter;
		}
	}
	return ' ';
}


int main() {
	int T; cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		INT n, p, l; cin >> n >> p >> l;
		int left = p - 1;
		int right = left + l - 1;

		for (int i = left; i <= right; i++) {
			INT dup = i;
			char ret = Func("FX", n, dup);
			cout << ret;
		}
		cout << endl;
	}

	return 0;
}