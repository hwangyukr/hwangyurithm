#include <iostream>
#include <string.h>
using namespace std;
char table[5][5];
int cache[100][10];
int N;

// 0430 90Ка
void input_table() {
	for (int i = 0; i < 5; i++) {
		char temp[6];
		cin >> temp;
		for (int j = 0; j < 5; j++) {
			table[i][j] = temp[j];
		}
	}
	cin >> N;
}
bool dp(int y, int x, int n, const char* word) {
	int& ret = cache[(y + 1) * 10 + (x + 1)][n];
	if (ret >= 0) return (bool)ret;

	if (n == 0) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (table[i][j] == word[n]) {
					if (dp(i, j, n + 1, word) == true) {
						ret = true;
						return true;
					}
				}
			}
		}
		ret = false;
		return false;
	}

	if (n > strlen(word) - 1) {
		ret = true;
		return true;
	}
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {
			if (i < 0 || j < 0 || i >= 5 || j >= 5) continue;
			if (i == y && j == x) continue;
			if (table[i][j] == word[n]) {
				if (dp(i, j, n + 1, word)) {
					ret = true;
					return true;
				}
			}
		}
	}
	ret = false;
	return false;
}

bool is_word_exist(const char* word) {
	for(int i=0; i<100; i++)
		memset(cache[i], -1, 10 * 4);

	return dp(-1, -1, 0, word);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		input_table();
		for (int i = 0; i < N; i++) {
			char word[101];
			cin >> word;
			bool chk = is_word_exist(word);
			cout << word << " " << (chk ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
