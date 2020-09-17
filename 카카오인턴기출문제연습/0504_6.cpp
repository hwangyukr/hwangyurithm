#include <string>
#include <vector>

using namespace std;

typedef vector<vector<char>> BOARD;

void erase_4_blocks(BOARD src, BOARD &dest, int h, int w) {
    dest = src;
    for (int i = 0; i < h-1; i++) { 
        for (int j = 0; j < w-1; j++) {
            char c1 = src[i][j];
            char c2 = src[i][j+1];
            char c3 = src[i+1][j];
            char c4 = src[i+1][j+1];
            if (c1 == c2 && c2 == c3 && c3 == c4) {
                dest[i][j] = -1;
                dest[i][j+1] = -1;
                dest[i+1][j] = -1;
                dest[i+1][j+1] = -1;
            }
        }
    }
}

char find_close(BOARD& target, int y, int x) {
    while (target[y][x] == -1) {
        y--;
        if (y < 0) return -1;
    }
    char ret = target[y][x];
    target[y][x] = -1;
    return ret;
}

void arrange_blocks(BOARD src, BOARD& dest, int h, int w) {
    dest = src;
    for (int i = h-1; i >=0; i--) {
        for (int j = 0; j < w; j++) {
            dest[i][j] = find_close(dest, i, j);
        }
    }
}

void create_board(vector<string> board, BOARD &dest) {
    for (int i = 0; i < board.size(); i++) {
        string row = board[i];
        for (int j = 0; j < row.length(); j++) {
            dest[i][j] = row[j];
        }
    }
}

bool same(BOARD A, BOARD B) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

int count_empty(BOARD T) {
    int ret = 0;
    for (int i = 0; i < T.size(); i++) {
        for (int j = 0; j < T[i].size(); j++) {
            if (T[i][j] == -1) ret++;
        }
    }
    return ret;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    BOARD B(m, vector<char>(n)); // 높이가 m임 주의
    create_board(board, B);

    while (true) {
        BOARD erased(m, vector<char>(n));
        BOARD arranged(m, vector<char>(n));
        erase_4_blocks(B, erased, m, n);
        arrange_blocks(erased, arranged, m, n);
        B = arranged;
        if (same(erased, arranged) == true) break;
    }

    answer = count_empty(B);
    return answer;
}

int main() {
    vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    int t = solution(6, 6, board);
    return 0;
}