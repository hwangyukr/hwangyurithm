#include <string>
#include <vector>
#include <iostream>
using namespace std;

double parse(string row, int& h, int& m, double& s, double& d) {
    sscanf(row.c_str(), "2016-09-15 %d:%d:%lf %lfs", &h, &m, &s, &d);
    double time = s + 60*m + 3600*h;
    return time;
}

bool is_cross(double s1, double e1, double s2, double e2) {
    if (s1 > e2) return false;
    if (e1 < s2) return false;
    return true;
}

int solution(vector<string> lines) {
    int answer = 0;
    int stk = 0;
    int maxi = 0;
    vector<double> vs, ve;
    for (int i = 0; i < lines.size(); i++) {
        string row = lines[i];
        int h, m;
        double s, d;
        double etime = parse(row, h, m, s, d);
        double stime = etime - d;
        int cnt = 1; // self count
        
        for (int i = 0; i < vs.size(); i++) {
            if (is_cross(stime, etime, vs[i], ve[i])) {
                cnt++;
            }
        }
        if (maxi < cnt) maxi = cnt;
        vs.push_back(stime);
        ve.push_back(etime);

    }
    answer = maxi;
    return answer;
}
int main() {
    vector<string> lines = {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"
    };
    int ans = solution(lines);
    return 0;
}
