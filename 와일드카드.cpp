// Lim Hwangyu
// https://algospot.com/judge/problem/read/WILDCARD

#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
typedef string S;
string _n[10][50], _wild[10];
priority_queue<S,vector<S>,greater<S>> pq;
int c_num = 0, n_num[10];
bool tr(S& wild, S& str, int wp, int sp);
int main() {
	cin>>c_num;
	for (int i=0;i<c_num;i++) {
		cin>>_wild[i]>>n_num[i];
		for(int j=0; j<n_num[i];j++) cin>>_n[i][j];
	}
	for (int i=0; i<c_num; i++) {
		for (int j = 0; j < n_num[i]; j++) {
			tr(_wild[i], _n[i][j], 0, 0);
		}
		while(!pq.empty()){cout<<pq.top()<< endl;pq.pop();}
	}
	return 0;
}
bool tr(S& w,S& str,int wp,int sp) {
	if (wp>w.length()||sp>str.length()) {
		bool coincide=wp>w.length()&&sp>str.length();
		if (coincide) pq.push(str);
		return coincide;
	}
	if (w[wp]==str[sp]||w[wp]=='?') {
		if(tr(w,str,wp+1,sp+1)) return true;
	}
	if (w[wp]=='*') {
		for (int i = 0;i<str.length()-sp+1;i++) {
			if(tr(w,str,wp+1,sp+i)) return true;
		}
	}
	return false;
}
