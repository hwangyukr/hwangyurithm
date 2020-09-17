#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool perfect(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    return (cnt == 0);
}

string solve(string w) {
    if (w == "") return "";
    string u, v;

    int cnt = 0, pos = -1;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(') cnt++;
        else cnt--;
        if (cnt == 0) {
            pos = i;
            break;
        }
    }

    u = w.substr(0, pos + 1);
    v = w.substr(pos + 1, w.size() - pos - 1);

    if (perfect(u) == true) {
        return u + solve(v);
    }
    
    string ret = "(";
    ret = ret + solve(v);
    ret = ret + ")";
    u = u.substr(1, u.size() - 2);
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(') u[i] = ')';
        else u[i] = '(';
    }
    ret = ret + u;
    return ret;
}

string solution(string p) {
    string answer = solve(p);

    return answer;
}

int main() {
    cout << solution(")(") << endl;
    cout << solution("()))((()") << endl;
    cout << solution("(()())()") << endl;
    return 0;
}
