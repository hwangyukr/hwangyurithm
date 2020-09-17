#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int parse_min(string t) {
    string str_h = string() + t[0] + t[1];
    string str_m = string() + t[3] + t[4];
    int ret = atoi(str_h.c_str()) * 60 + atoi(str_m.c_str());
    return ret;
}

string parse_str(int min) {
    int h = min / 60;
    int m = min % 60;
    
    char ch[10];
    ch[0] = '0' + (h / 10);
    ch[1] = '0' + (h % 10);
    ch[2] = ':';
    ch[3] = '0' + (m / 10);
    ch[4] = '0' + (m % 10);
    ch[5] = '\0';
    return string(ch);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < timetable.size(); i++) {
        int time = parse_min(timetable[i]);
        pq.push(time);
    }
    int empty_bus_late = -1;
    int bus_time = 540;
    int bus_num = 0;
    int bus_member = 0;
    
    int last_go_member = 0;
    int last_bus_member = 0;
    
    while (!pq.empty()) {
        bus_member = 0;
        last_bus_member = 0;
        for (int i = 0; i < m; i++) {
            if (pq.empty()) break;
            int top = pq.top();
            if (top <= bus_time) {
                bus_member++;
                pq.pop();
                last_go_member = top;
            }
            last_bus_member = bus_member;
        }

        bus_num++;
        if (bus_num >= n) break;
        bus_time += t;
    }

    int have_to_go_time;
    if (last_bus_member >= m) {
        have_to_go_time = last_go_member - 1; // 1ºÐ »¡¸®
    }
    else {
        have_to_go_time = bus_time; // ¹ö½ºµµÂø½Ã°£
    }

    answer = parse_str(have_to_go_time);
    return answer;
}

int main() {
    vector<string> times = { "08:00", "08:01", "08:02", "08:03" };
    string ans = solution(1, 1, 5, times);
    return 0;
}