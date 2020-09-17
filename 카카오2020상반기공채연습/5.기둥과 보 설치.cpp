#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(vector<vector<int>> &map_0, vector<vector<int>> &map_1) {
    int sz = map_0.size();
    for (int x = 0; x < sz; x++) {
        for (int y = 0; y < sz; y++) {
            int l = map_0[x][y];
            int b = map_1[x][y];

            if (l == 1) { // ±âµÕ
                bool chk1 = (y == 0); // ¹Ù´Ú¿¡ ±âµÕ
                bool chk2 = (y > 0 && map_0[x][y - 1] == 1); // ±âµÕ ¾Æ·¡ ±âµÕ
                bool chk3 = (x > 0 && map_1[x - 1][y] == 1); // ±âµÕÀÌ º¸ ¿À¸¥ÂÊ¿¡
                bool chk4 = (map_1[x][y] == 1); // ±âµÕÀÌ º¸ ¿ÞÂÊ¿¡
                if (chk1 == false && chk2 == false && chk3 == false && chk4 == false)
                    return false;
            }

            if (b == 1) { // º¸
                bool chk1 = (y > 0 && map_0[x][y - 1] == 1); // º¸ ¿ÞÂÊ ±âµÕ
                bool chk2 = (x < sz-1 && y > 0 && map_0[x+1][y - 1] == 1); // º¸ ¿À¸¥ÂÊ ±âµÕ
                bool left_bo = (x > 0) && (map_1[x - 1][y]==1);
                bool right_bo = (x < sz - 1) && (map_1[x + 1][y]==1);
                bool chk3 = (left_bo && right_bo); // º¸ ¾çÂÊ¿¡ º¸
                if (chk1 == false && chk2 == false && chk3 == false)
                    return false;
            }

        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    n = n + 1;

    vector<vector<int>> answer;
    vector<vector<int>> map[2];
    map[0] = vector<vector<int>>(n, vector<int>(n, 0));
    map[1] = vector<vector<int>>(n, vector<int>(n, 0));
    
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int what = build_frame[i][2];
        int how = build_frame[i][3];

        int backup = map[what][x][y];
        if (how == 0) map[what][x][y] = 0;
        if (how == 1) map[what][x][y] = 1;

        if (check(map[0], map[1]) == false) { // ¹®Á¦¹ß»ý
            map[what][x][y] = backup; // º¹±¸
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int l = map[0][x][y];
            int b = map[1][x][y];
            if (l == 1) {
                answer.push_back({ x, y, 0 });
            }
            if (b == 1) {
                answer.push_back({ x, y, 1 });
            }
        }
    }
    
    return answer;
}

int main() {
    //vector<vector<int>> t1 = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    //solution(5, t1);
    vector<vector<int>> t2 = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    vector<vector<int>> ans = solution(5, t2);

    return 0;
}