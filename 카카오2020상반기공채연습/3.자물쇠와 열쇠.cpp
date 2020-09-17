#include <iostream>
#include <string>
#include <vector>
using namespace std;
using MAP = vector<vector<int>>;

void gen_big_key(MAP key, vector<MAP> &ret) {
    int size = key.size();

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ret[0][size + i][size + j] = key[i][j]; // 원본

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ret[1][size + i][size + j] = ret[0][size + j][size * 2 - i -1]; // 90도 회전

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ret[2][size + i][size + j] = ret[1][size + j][size * 2 - i-1]; // 90도 회전

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ret[3][size + i][size + j] = ret[2][size + j][size * 2 - i-1]; // 90도 회전

}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int size = key.size();

    vector<MAP> big_key(4, vector<vector<int>>(size * 3, vector<int>(size * 3, 0)));
    gen_big_key(key, big_key);

    for (int dir = 0; dir < 4; dir++) {
        for (int y = 0; y <= size * 2; y++) {
            for (int x = 0; x <= size * 2; x++) {
                for (int offy = 0; offy <= lock.size() - key.size(); offy++) {
                    for (int offx = 0; offx <= lock.size() - key.size(); offx++) {
                        vector<vector<bool>> check(lock.size(), vector<bool>(lock.size(), false));
                        answer = true;

                        for (int i = 0; i < size; i++) {
                            for (int j = 0; j < size; j++) {
                                int k = big_key[dir][y + i][x + j];
                                int l = lock[offy + i][offx + j];
                                if (k == 1 && l == 1) answer = false;
                                if (k == 0 && l == 0) answer = false;
                                if (answer == false) break;
                                else check[offy + i][offx + j] = true;
                            }
                            if (answer == false) break;
                        }

                        bool open = true;
                        for (int i = 0; i < lock.size(); i++) {
                            for (int j = 0; j < lock.size(); j++) {
                                if (check[i][j] == true) continue;
                                if (lock[i][j] == 1) continue;
                                answer = false;
                                break;
                            }
                        }

                        if (answer == true) return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> t1 = { {0,0,0}, {1,0,0}, {0,1,1} };
    vector<vector<int>> t2 = { {1,1,1}, {1,1,0}, {1,0,1} };
    cout << (bool)solution(t1, t2) << endl;

    vector<vector<int>> t3 = { { 1,1,1 }, { 1,1,1 }, { 1,1,1 } };
    vector<vector<int>> t4 = { { 0,1,1 }, { 0,0,1 }, { 0,1,1 } };
    cout << (bool)solution(t3, t4) << endl;
    return 0;
}
