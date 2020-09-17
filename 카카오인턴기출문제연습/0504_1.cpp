#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string parse_bin(int k, int n) {
    string str = "";
    stack<char> st;
    for(int i=0; i<n; i++) {
        int r = k % 2;
        if (r == 0) st.push(' ');
        else st.push('#');
        k = k / 2;
    }

    while (!st.empty()) {
        char t = st.top();
        str += t;
        st.pop();
    }

    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); i++) {
        int row = arr1[i] | arr2[i];
        string str = parse_bin(row, n);
        answer.push_back(str);
    }
    return answer;
}

int main() {
    int n = 5;
    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };
    vector<string> res = solution(n, arr1, arr2);
}
