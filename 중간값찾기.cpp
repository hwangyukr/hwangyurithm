// Lim Hwangyu
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QPsXKA2UDFAUq&categoryId=AV5QPsXKA2UDFAUq&categoryType=CODE
#include <iostream>
#include <string>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		pq.push(input);
	}
	for (int i = 0; i < n/2; i++) pq.pop();
	cout << pq.top() << endl;
	return 0;
}
