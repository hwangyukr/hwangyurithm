#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 100 min
struct Item {
	string name;
	int weight;
	int need;
};

struct cacheItem {
	int isSelected;
	int nextSpace;
	int value;
};

int packing(int n, vector<Item>& itemVector, vector<vector<cacheItem>>& cache, int pos, int space) {
	if (pos > n - 1) return 0;
	Item& now = itemVector[pos];
	if (space < 0) return 0;
	cacheItem& ret = cache[pos][space];
	if (ret.value >= 0) return ret.value;
	int res1 = 0;
	if (space >= now.weight) res1 = now.need + packing(n, itemVector, cache, pos + 1, space - now.weight);
	int res2 = packing(n, itemVector, cache, pos + 1, space);
	if (res1 > res2) {
		ret.isSelected = 1;


		ret.value = res1;
		ret.nextSpace = space - now.weight;
	}
	else {
		ret.isSelected = 0;
		ret.value = res2;
		ret.nextSpace = space;
	}
	return ret.value;
}

void getNames(int n, vector<string>& det, vector<vector<cacheItem>>& cache, int pos, int space, vector<Item>& itemVector) {
	if (pos > n - 1) return;
	Item& now = itemVector[pos];
	cacheItem iter = cache[pos][space];
	if (iter.isSelected < 0) return;
	if (iter.isSelected == 1) det.push_back(now.name);
	getNames(n, det, cache, pos+1, iter.nextSpace, itemVector);
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n, w; cin >> n >> w;
		vector<Item> itemVector(n, { "",0,0 });
		vector<vector<cacheItem>> cache(n, vector<cacheItem>(1001, { -1, -1, -1 }));
		vector<int> packed(n, 0);
		for (int i = 0; i < n; i++)
			cin >> itemVector[i].name >> itemVector[i].weight >> itemVector[i].need;
		int res = packing(n, itemVector, cache, 0, w);

		vector<string> det;
		getNames(n, det, cache, 0, w, itemVector);
		cout << res << " " << det.size() << endl;
		for (int i = 0; i < det.size(); i++)
			cout << det[i] << endl;
	}
}