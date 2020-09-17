#include <string>
#include <vector>
using namespace std;

bool can_put(vector<vector<int>> &board, int y, int x) {
    for (int i = 0; i < y - 1; i++) {
        if (board[i][x] != 0) return false;
    }
    return true;
}

void full_drop();
void compare();

int solution(vector<vector<int>> board) {
    int answer = 0;
    for (int i = board.size() - 2; i >= 0; i --) {
        vector<int>& row = board[i];
        for (int j = 0; j < row.size(); j++) {
            if (board[i][j] != 0) continue;
            bool cp = can_put(board, i, j);
            if (cp == true) {
                board[i][j] = board[i+1][j];
            }
        }
    }

    return answer;
}

int main() {
    int ans = solution(
        {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 4, 4, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 4, 0, 0, 0}, {0, 0, 0, 2, 3, 0, 0, 0, 5, 5}, {1, 2, 2, 2, 3, 3, 0, 0, 0, 5}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}}
    );


    return 0;
}