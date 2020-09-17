#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MIN 0x80000000

// 80min
int jlis(int pa, int pb, int *a, int *b, int n, int m, int cache[102][102]) {
	int& ret = cache[pa + 1][pb + 1];
	if (ret != 0) return ret;

	int a_val, b_val;
	if (pa == -1) a_val = MIN;
	else a_val = a[pa];
	if (pb == -1) b_val = MIN;
	else b_val = b[pb];

	int bigger = max(a_val, b_val);
	for (int i = pa+1; i < n; i++) {
		if(bigger < a[i])
			ret=max(ret,jlis(i, pb, a, b, n, m, cache));
	}
	for (int i = pb+1; i < m; i++) {
		if (bigger < b[i])
			ret=max(ret,jlis(pa, i, a, b, n, m, cache));
	}
	return (ret=ret+1);
}

int main() {
	int T; cin >> T;
	for (int test_num = 1; test_num <= T; test_num++) {
		int n, m; cin >> n >> m;
		int a[101], b[101], cache[102][102];
		memset(cache, 0, 102 * 102 * sizeof(int));
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		//sort(a, a + n); 왜 정렬을 해서 30분 넘게 헤맸을까 이해할 수가 없네...
		//sort(b, b + m);
		int ans = jlis(-1,-1,a,b,n,m,cache) - 1;
		cout << ans << endl;
	}
	
	return 0;
}