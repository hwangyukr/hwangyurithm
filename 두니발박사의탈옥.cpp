// Lim Hwangyu
// https://algospot.com/judge/problem/read/NUMB3RS

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int c, n[50], day[50], prison[50], t[50], q[50][50];
int adj[50][50][50];
double chance_table[50];

void update(int T) {
	double new_table[50];
	for (int i = 0; i < n[T]; i++) new_table[i] = 0;
	for (int i = 0; i < n[T]; i++) {
		int _t = 0;
		for (int j = 0; j < n[T]; j++) _t += adj[T][i][j];
		for (int j = 0; j < n[T]; j++) {
			if (adj[T][i][j] == 1) {
				new_table[j] += chance_table[i] / (double)_t;
			}
		}
	}
	for (int i = 0; i < n[T]; i++) chance_table[i] = new_table[i];
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(8);
	cin >> c;
	for (int T = 0; T < c; T++) {
		cin >> n[T] >> day[T] >> prison[T];
		for (int i = 0; i < n[T]; i++) for (int j = 0; j < n[T]; j++) cin >> adj[T][i][j];
		cin >> t[T];
		for (int i = 0; i < t[T]; i++) cin >> q[T][i];
	}

	for (int T = 0; T < c; T++) {
		for (int i = 0; i < n[T]; i++) chance_table[i] = 0.00;
		chance_table[prison[T]] = 1.00;
		for (int i = 0; i < day[T]; i++) update(T);
		for (int i = 0; i < t[T]; i++) cout << chance_table[q[T][i]] << " ";
		cout << endl;
	}
	return 0;
}
