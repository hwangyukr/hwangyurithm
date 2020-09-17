// Lim Hwangyu
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWd7sgDatsMDFAUh&categoryId=AWd7sgDatsMDFAUh&categoryType=CODE
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case; int T; cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		cin >> n >> k;
		priority_queue<int, vector<int>, less<int>> pq;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			pq.push(t);
		}

		vector<int> vec;
		for (int i = 0; i < k; i++) {
			vec.push_back(pq.top());
			pq.pop();
		}

		double t = 0.0;
		for (int i = k - 1; i >= 0; i--) {
			t = (t + vec[i]) / 2.0;
		}

		cout << "#" << test_case << " ";
		cout << t << endl;

	}
	return 0;
}
