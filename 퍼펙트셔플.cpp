// Lim Hwangyu
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWGsRbk6AQIDFAVW&categoryId=AWGsRbk6AQIDFAVW&categoryType=CODE

#include <iostream>
#include <string>
using namespace std;
int c, n[10];
string card[10][1000];
string shuffle(string str[], int num) {
	string result = "";
	int mid = num / 2 + int(num%2 != 0);
	for (int i = 0; i < mid; i++) {
		result.append(str[i]); result.append(" ");
		result.append(str[i + mid]); result.append(" ");
	}
	return result;
}

int main(int argc, char** argv) {
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n[i];
		for (int j = 0; j < n[i]; j++) cin >> card[i][j];
	}
	for (int i = 0; i < c; i++)
		cout << "#" << i+1 << " " << shuffle(card[i], n[i]) << endl;
	return 0;
}
