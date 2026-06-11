class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        vector<int> rows(n, 0), cols(n, 0), blocks(n, 0);
        auto attempt = [&](int bit, int &mask) -> bool {
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
                int k = i / 3 * 3 + j / 3, bit = 1 << board[i][j] - '1';
                if (!attempt(bit, rows[i]) || !attempt(bit, cols[j]) || !attempt(bit, blocks[k])) {
                    return false;
                }
            }
        }
        return true;
    }
};
