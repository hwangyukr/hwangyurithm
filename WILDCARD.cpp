#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> cache(101, vector<int>(101, -1));

// 40min
int wildcard(string& key, string& target, int k=0, int p=0) {
	int& ret = cache[k][p];
	if (ret != -1) return ret;

	if (p > target.length() - 1 && k > key.length() - 1) return (ret=1);
	else if (k > key.length() - 1) return (ret = 0);

	if (key[k] == target[p]) return (ret=wildcard(key, target, k + 1, p + 1));
	if (key[k] == '?') return (ret=wildcard(key, target, k + 1, p + 1));
	if (key[k] == '*') {
		bool avail = false;
		for (int i = p; i < target.size()+1; i++) {
			avail = wildcard(key, target, k + 1, i);
			if (avail == true) return (ret=true);
		}
	}
	return (ret=false);
}

int main() {
	int T; cin >> T;
	for (int test_num = 1; test_num <= T; test_num++) {
		vector<string> answer;
		string key; cin >> key;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string target;
			cin >> target;
			cache = vector<vector<int>>(101, vector<int>(101, -1));
			// 캐시 초기화 빼먹어서 오답...1
			// 정렬해서 출력하기 ... 문제 안읽어서 10분버리고 오답...2
			int available = wildcard(key, target);
			if (available == 1) answer.push_back(target);
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;
	}
	return 0;
}