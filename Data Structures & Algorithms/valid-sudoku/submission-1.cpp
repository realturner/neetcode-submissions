// 16:20
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        int mask = 0;
        auto hasOverlap = [&](int i, int j) {
            if (board[i][j] == '.') {
                return false;
            }
            int bit = 1 << board[i][j] - '0';
            if (mask & bit) {
                return true;
            }
            mask |= bit;
            return false;
        };
        for (int i = 0; i < n; i++) {
            mask = 0;
            for (int j = 0; j < n; j++) {
                if (hasOverlap(i, j)) {
                    return false;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            mask = 0;
            for (int i = 0; i < n; i++) {
                if (hasOverlap(i, j)) {
                    return false;
                }
            }
        }
        for (int block = 0; block < n; block++) {
            mask = 0;
            for (int subBlock = 0; subBlock < n; subBlock++) {
                if (hasOverlap(block / 3 * 3 + subBlock / 3, block % 3 * 3 + subBlock % 3)) {
                    return false;
                }
            }
        }
        return true;
    }
};
