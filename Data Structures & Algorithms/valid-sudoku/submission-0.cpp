// 16:20
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0, mask = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int bit = 1 << board[i][j] - '0';
                if (mask & bit) {
                    return false;
                }
                mask |= bit;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0, mask = 0; i < n; i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int bit = 1 << board[i][j] - '0';
                if (mask & bit) {
                    return false;
                }
                mask |= bit;
            }
        }
        for (int block = 0; block < n; block++) {
            for (int subBlock = 0, mask = 0; subBlock < n; subBlock++) {
                auto &ch = board[block / 3 * 3 + subBlock / 3][block % 3 * 3 + subBlock % 3];
                if (ch == '.') {
                    continue;
                }
                int bit = 1 << ch - '0';
                if (mask & bit) {
                    return false;
                }
                mask |= bit;
            }
        }
        return true;
    }
};
