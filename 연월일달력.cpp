// Lim Hwangyu
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq&categoryId=AV5QLkdKAz4DFAUq&categoryType=CODE
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int monthdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
	string n[10];
	int c; cin >> c;
	for (int i = 0; i < c; i++) cin >> n[i];

	for (int i = 0; i < c; i++) {
		string &str = n[i];
		int year = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
		int month = (str[4] - '0') * 10 + (str[5] - '0');
		int day = (str[6] - '0') * 10 + (str[7] - '0');

		if (month < 1 || month > 12 || day < 1 || day > monthdays[month - 1]) cout << '#' << i + 1 << ' ' << -1 << endl;
		else {
			char ch[10];
			cout << '#' << i + 1 << ' ';
			cout << setfill('0') << setw(4) << year << '/';
			cout << setfill('0') << setw(2) << month << '/';
			cout << setfill('0') << setw(2) << day << endl;
		}

	}
	return 0;
}
