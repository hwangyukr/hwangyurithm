#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string inttostr(int t) {
    string ret = "";
    while (true) {
        char digit = t % 10 + '0';
        t = t / 10;
        ret = digit + ret;
        if (t <= 0) break;
    }
    return ret;
}

int solution(string s) {
    int answer = 0;
    int len = s.size();

    int mini = s.size();

    for (int i = 1; i <= len/2; i++) {
        string encoded = "";
        string key = s.substr(0, i);
        int encode_cnt = 1;
        int pos;
        for (pos = i; pos < len; pos += i) {
            string comp = s.substr(pos, i);

            if (key == comp) {
                encode_cnt++;
            }

            if (key != comp) {
                if (encode_cnt > 1) {
                    encoded = encoded + inttostr(encode_cnt);
                }
                encoded = encoded + key;
                encode_cnt = 1;
                key = s.substr(pos, i);
            }
        }

        if (encode_cnt > 1) {
            encoded = encoded + inttostr(encode_cnt);
        }
        encoded = encoded + key;

        for (pos; pos < len; pos++) {
            encoded = encoded + s[pos];
        }
        
        mini = min(mini, (int)encoded.size());
        //cout << encoded << endl;
    }

    answer = mini;
    return answer;
}

int main() {
    cout << solution("aaaaaaaaaaaa") << endl;
    cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    cout << solution("abcabcdede") << endl;
    cout << solution("abcabcabcabcdededededede") << endl;
    cout << solution("xababcdcdababcdcd") << endl;
    return 0;
}
