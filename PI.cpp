// 쉽지않은데?
// 75min

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
void get_seqs(vector<int>& numbers, int p, int &distance, int &num) {
	if (p > numbers.size() - 2) {
		distance = 0;
		num = 0;
		return;
	}

	distance = numbers[p] - numbers[p+1];
	int cnt = 1;
	while (p+1 < numbers.size() && (numbers[p] - numbers[p+1]) == distance) {
		cnt++;
		p++;
	}
	num = cnt;
}

int get_alter(vector<int>& numbers, int p) {
	int cnt = 0;
	if (p == numbers.size() - 1) return cnt;
	int l = numbers[p];
	int r = numbers[p + 1];
	int t = l;
	while (p < numbers.size() && (numbers[p] == t)) {
		if (t == l) t = r;
		else t = l;
		cnt++;
		p++;
	}
	return cnt;
}

int find_mini_cost(vector<int> &numbers, int p, vector<int> &cache) {
	if (p == numbers.size()) return 0; // p == numbers.size()-1 로 했다가 헤맴...
	if (p > numbers.size()) return MAX;
	int& ret = cache[p];

	if (ret != MAX) return ret;
	int distance, seq_num;
	get_seqs(numbers, p, distance, seq_num);
	if (seq_num > 5) seq_num = 5;

	if (distance == 0)
		for (int i = 3; i <= seq_num; i++)
			ret = min(ret, find_mini_cost(numbers, p + i, cache) + 1);

	if (distance == -1 || distance == 1)
		for (int i = 3; i <= seq_num; i++)
			ret = min(ret, find_mini_cost(numbers, p + i, cache) + 2);
	
	int alter_num = get_alter(numbers, p);
	if (alter_num > 5) alter_num = 5;

	for (int i = 3; i <= alter_num; i++)
		ret = min(ret, find_mini_cost(numbers, p + i, cache) + 4);

	if (distance != -1 && distance != 1 && distance != 0)
		for (int i = 3; i <= seq_num; i++)
			ret = min(ret, find_mini_cost(numbers, p + i, cache) + 5);

	ret = min(ret, find_mini_cost(numbers, p + 3, cache) + 10);
	ret = min(ret, find_mini_cost(numbers, p + 4, cache) + 10);
	ret = min(ret, find_mini_cost(numbers, p + 5, cache) + 10);
	return ret;
}

int main() {
	int T; cin >> T;
	for (int test_num = 1; test_num <= T; test_num++) {
		string row; cin >> row;
		vector<int> numbers(row.length());
		vector<int> cache(row.length()+1, MAX);
		for (int i = 0; i < row.length(); i++) numbers[i] = row[i]-'0';
		int ans = find_mini_cost(numbers, 0, cache);
		cout << ans << endl;
	}

}