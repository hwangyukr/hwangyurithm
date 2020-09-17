// Lim Hwangyu
// https://algospot.com/judge/problem/submit/TRIANGLEPATH

#include <iostream>
using namespace std;

int n;
int a[100][100];
int cache[100][100];

int tripath(int y, int x, int sum) {
  if(y >= n) return sum;
  int s = sum + a[y][x];
  int l, r;
  l = r = s;
  if(s > cache[y][x]) {
	cache[y][x] = s;
	l = tripath(y+1, x, s);
	r = tripath(y+1, x+1, s);
  }

  int m = (l > r ? l : r);
  return m;
}

int main() {
  int c; cin>>c;
  int result[100];
  for(int i=0; i<c; i++) {
	cin >> n;

	for(int j=0; j<n; j++) {
	 	for(int k=0; k<j+1; k++) {
		 	cin >> a[j][k];
		  	cache[j][k] = 0;
		}
	}
	result[i] = tripath(0,0,0);
  }
  
  for(int i=0; i<c; i++) {
	cout << result[i] << endl;
  }
  
  return 0; 
}
