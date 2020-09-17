// Lim Hwangyu
// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWRurBkKkKADFAXt&categoryId=AWRurBkKkKADFAXt&categoryType=CODE

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int l, k;
char a[2001];
int icost[30];
int dcost[30];
int d[2001][2001];

int main(int argc, char** argv)
{
	int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++) {
        cin >> l >> k;
        cin >> a;
        for(int i=0;  i<k; i++) {
        	cin >> icost[i];
            cin >> dcost[i];
        }

        for(int i=0; i<l; i++) {
        	d[0][i] = 0;
            d[1][i] = 0;
        }
        for(int i=2; i<=l; i++) {
            for(int j=0; j<l-i+1; j++) { // d[i][j] 구하기
                int mini = 1000000000, temp;
                temp = d[i-1][j+1] + dcost[a[j]-'a'];
                if(mini > temp) mini = temp;
                temp = d[i-1][j+1] + icost[a[j]-'a'];
                if(mini > temp) mini = temp;
                temp = d[i-1][j] + icost[a[j+i-1] - 'a'];
                if(mini > temp) mini = temp;
                temp = d[i-1][j] + dcost[a[j+i-1] - 'a'];
                if(mini > temp) mini = temp;
                if(a[j] == a[i+j-1]) temp = d[i-2][j+1];
                if(mini > temp) mini = temp;
                d[i][j] = mini;
            }
        }

        cout << "#" << test_case << " " << d[l][0] << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
