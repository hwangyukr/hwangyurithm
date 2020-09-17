#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef map<string, int> MAP;

void convert_upper(string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a';
            str[i] += 'A';
        }
    }
}

void create_set(string str, MAP& dest) {
    dest.clear();
    for (int i = 0; i < str.length()-1; i++) {
        char c1 = str[i];
        char c2 = str[i+1];
        if (c1 > 'Z' || c1 < 'A') continue;
        if (c2 > 'Z' || c2 < 'A') continue;
        string key = string() + c1 + c2;
        dest[key] ++;
    }
}

void uni(MAP A, MAP B, MAP& U) {
    U.clear();
    for (auto iter = A.begin(); iter != A.end(); iter++) {
        string k = iter->first;
        int v = iter->second;
        U[k] = max(A[k], B[k]);
    }

    for (auto iter = B.begin(); iter != B.end(); iter++) {
        string k = iter->first;
        int v = iter->second;
        U[k] = max(A[k], B[k]);
    }
}

void inter(MAP A, MAP B, MAP& I) {
    I.clear();
    for (auto iter = A.begin(); iter != A.end(); iter++) {
        string k = iter->first;
        int v = iter->second;
        I[k] = min(A[k], B[k]);
    }

    for (auto iter = B.begin(); iter != B.end(); iter++) {
        string k = iter->first;
        int v = iter->second;
        I[k] = min(A[k], B[k]);
    }
}

int count_cardinality(MAP target) {
    int ret = 0;
    for (auto iter = target.begin(); iter != target.end(); iter++) {
        //ret += (iter->second > 0);
        ret += (iter->second);
    }
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    MAP A, B;
    MAP U, I;
    convert_upper(str1);
    convert_upper(str2);
    create_set(str1, A);
    create_set(str2, B);

    int card_A = count_cardinality(A);
    int card_B = count_cardinality(B);
    if (card_A + card_B == 0) {
        return 65536;
    }

    uni(A, B, U);
    inter(A, B, I);

    int card_U = count_cardinality(U);
    int card_I = count_cardinality(I);

    answer = ((double)card_I / card_U) * 65536;
    return answer;
}

int main() {
    int j = solution("FRANCE", "french");
    return 0;
}