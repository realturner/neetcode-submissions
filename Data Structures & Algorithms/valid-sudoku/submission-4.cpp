// 16:20
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        vector<int> rows(n, 0), cols(n, 0), blocks(n, 0);
        auto attempt = [](int &mask, int bit) {
            if (mask & bit) {
                return false;
            }
            mask |= bit;
            return true;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int bit = 1 << board[i][j] - '0';
                int bid = i / 3 * 3 + j / 3;
                if (!attempt(rows[i], bit) || !attempt(cols[j], bit) || !attempt(blocks[bid], bit)) {
                    return false;
                }
            }
        }
        return true;
    }
};
