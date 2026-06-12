// 12:24
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size();
        vector seen(m, vector<bool>(n, false));
        auto go = [&](this auto &&go, int i, int j, string::iterator it) -> bool {
            if (it == word.end()) {
                return true;
            } else if (i < 0 || i >= m || j < 0 || j >=n || *it != board[i][j] || seen[i][j]) {
                return false;
            }
            seen[i][j] = true;
            ++it;
            bool ans = go(i + 1, j, it) || go(i - 1, j, it) || go(i, j + 1, it) || go(i, j - 1, it);
            seen[i][j] = false;
            return ans;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (go(i, j, word.begin())) {
                    return true;
                }
            }
        }
        return false;
    }
};
