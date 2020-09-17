#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000000
// 120min 어려웠다..

int sub_avg(vector<int>& inputs, int l, int r) {
	if (r == l) return MAX;
	int sum = 0;
	for (int i = l; i < r; i++) sum += inputs[i];
	int num = r - l;
	return int((double)sum / num + 0.5);
}

int sub_err(vector<int>& inputs, int l, int r) {
	int avg = sub_avg(inputs, l, r);
	int sum = 0;
	for (int i = l; i < r; i++) sum += (inputs[i]-avg) * (inputs[i] - avg);
	return sum;
}

// 같은 파라미터가 항상 같은 답을 내면 (독립) 무조건 메모이제이션
// 독립인지 검사하는 방법 -> 공유 데이터 조작이 없었다면 거의 독립인듯
int quantize_mini_error(vector<int>& inputs, int s, int p, int thr, vector<vector<int>> &cache) {
	if (p > inputs.size() - 1) return 0;
	if (thr > s - 1) return MAX;

	int& ret = cache[p][thr];
	if (ret != MAX) return ret;

	for (int i = p; i < inputs.size(); i++) { // p~i 까지 넣은걸로
		int err = sub_err(inputs, p, i+1);
		ret = min(ret, quantize_mini_error(inputs, s, i+1, thr+1, cache) + err);
	}

	return ret;
}

int main() {
	int T; cin >> T;
	for (int test_num = 1; test_num <= T; test_num++) {
		int n, s; cin >> n >> s;
		vector<int> inputs(n);
		vector<vector<int>> cache(n+1, vector<int>(s+1, MAX));
		for (int i = 0; i < n; i++) cin >> inputs[i];
		sort(inputs.begin(), inputs.end());
		int ans = quantize_mini_error(inputs, s, 0,0, cache);
		cout << ans << endl;
	}
}
