#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<int> used_col;

void create_case(int t, int n, vector<int>& dest) {
    for(int i=0; i<n; i++) {
        dest.push_back(t%2);
        t = t / 2;
    }
}

int can_be_key(vector<vector<string>> &relation, vector<int> &case_vec) {
    map<string, int> chk_col;
    string sum_key = "";
    for (int i = 0; i < relation.size(); i++) {
        vector<string> row = relation[i];
        sum_key = "";
        for (int j = 0; j < row.size(); j++) {
            if (case_vec[j] == 0) continue;
            if (used_col[j] == 1) continue;
            string a = row[j];
            sum_key += a;
        }
        if (chk_col[sum_key] > 0) {
            return 0; // colide
        }
        chk_col[sum_key] ++;
    }

    for (int i = 0; i < case_vec.size(); i++) {
        if(case_vec[i] == 1) used_col[i] = 1; // 키가 됐으면 재사용 불가
    }

    return 1; // can be key
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int cols = relation[0].size();
    int cases = 1;
    cases = cases << cols;
    used_col = vector<int>(cols, 0);

    for (int i = 1; i < cases; i++) {
        vector<int> case_vec;
        create_case(i, cols, case_vec);
        if (can_be_key(relation, case_vec) == 1) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<vector<string>> relation =
        {
            { "200", "zino", "2"},
            { "100", "zino", "2" },
            { "100", "ryan", "2" },
            { "200", "apeach", "2" },
            { "100", "ryan", "4" },
            { "200", "apeach", "3" },
        };

    int ans = solution(relation);
    return 0;
}