// 16:20
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        auto hasOverlap = [&](int i, int j, int &mask) {
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
            for (int j = 0, mask = 0; j < n; j++) {
                if (hasOverlap(i, j, mask)) {
                    return false;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0, mask = 0; i < n; i++) {
                if (hasOverlap(i, j, mask)) {
                    return false;
                }
            }
        }
        for (int block = 0; block < n; block++) {
            for (int subBlock = 0, mask = 0; subBlock < n; subBlock++) {
                if (hasOverlap(block / 3 * 3 + subBlock / 3, block % 3 * 3 + subBlock % 3, mask)) {
                    return false;
                }
            }
        }
        return true;
    }
};
