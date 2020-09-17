#include <string>
#include <iostream>
#include <math.h>
using namespace std;

struct SCORE {
    int score;
    int weight;
    int prize;
    int turn;
    int total;
};

int extract_score(string target, int& offset) {
    string str = "";
    for (int i = offset; i < target.length(); i++) {
        if (target[i] >= '0' && target[i] <= '9') {
            str += target[i];
            offset++;
        }
        else break;
    }
    int ret = atoi(str.c_str());
    return ret;
}

int extract_weight(string target, int& offset) {
    if (target[offset] == 'S') {
        offset++;
        return 1;
    }
    if (target[offset] == 'D') {
        offset++;
        return 2;
    }
    if (target[offset] == 'T') {
        offset++;
        return 3;
    }
    return 0;
}

int extract_prize(string target, int& offset) {
    if (target[offset] == '*') {
        offset++;
        return 1;
    }
    if (target[offset] == '#') {
        offset++;
        return 2;
    }
    return 0;
}

int append_score(SCORE& s, SCORE& ps) {
    int total = 1;
    for (int i = 0; i < s.weight; i++) { // SDT
        total *= s.score;
    }

    if (s.prize == 1) { // *
        if (s.turn == 0) total *= 2;
        else {
            total = total + total;
            total = total + ps.total;
        }
    }

    if (s.prize == 2) { // #
        total = -total;
    }

    s.total = total;
    return total;
}

int solution(string dartResult) {
    int answer = 0;
    int offset = 0;
    int total = 0;
    SCORE prev_score = { 0, 0, 0, 0 };

    int turn = 0;
    while (offset < dartResult.length()) {
        int score = extract_score(dartResult, offset);
        int weight = extract_weight(dartResult, offset);
        int prize = extract_prize(dartResult, offset);
        SCORE s = { score, weight, prize, turn };
        total += append_score(s, prev_score);
        //cout << score << " " << weight << " " << prize << " " << total << endl;
        if (offset >= dartResult.length()) break;
        turn++;
        prev_score = s;
    }

    answer = total;
    return answer;
}

int main() {
    int t = solution("1S2D*3T");
    return 0;
}