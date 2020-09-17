#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct STAGE {
    int number;
    double rate;
};

bool cmp(const STAGE& a, const STAGE& b){
    if (abs(a.rate - b.rate) < 1e-12) {
        return false;
    }
    if (a.rate > b.rate) return true;
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> passed(1000, 0);
    vector<int> staying(1000, 0);
    vector<STAGE> st;
    for (int i = 0; i < stages.size(); i++) {
        int reach = stages[i] - 1;
        staying[reach] ++;
    }

    int cnt = 0;
    for (int i = N+1; i >= 0; i--) {
        cnt += staying[i];
        passed[i] += cnt;
    }

    for (int i = 0; i < N; i++) {
        double r;
        if (passed[i] != 0) {
            r = 1.0 * staying[i] / passed[i];
        }
        else {
            r = 0;
        }
        st.push_back({ i + 1, r });
    }

    sort(st.begin(), st.end(), cmp);

    for (int i = 0; i < N; i++) {
        answer.push_back(st[i].number);
    }

    return answer;
}

int main() {
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    vector<int> sol = solution(5, stages);
    return 0;
}
