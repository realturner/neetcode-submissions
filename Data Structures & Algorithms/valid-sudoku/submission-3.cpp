// 16:20
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        vector<int> rows(n, 0), cols(n, 0), blocks(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int bit = 1 << board[i][j] - '0';
                if (rows[i] & bit) {
                    return false;
                }
                rows[i] |= bit;
                if (cols[j] & bit) {
                    return false;
                }
                cols[j] |= bit;
                int bid = i / 3 * 3 + j / 3;
                if (blocks[bid] & bit) {
                    return false;
                }
                blocks[bid] |= bit;
            }
        }
        return true;
    }
};
