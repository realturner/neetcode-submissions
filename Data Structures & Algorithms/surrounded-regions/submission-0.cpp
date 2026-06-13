// 17:59
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size(), n = board[0].size();
        queue<pair<int,int>> q;
        auto attempt = [&](int i, int j) {
            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O') {
                q.push({i, j});
                board[i][j] = '#';
            }
        };
        for (int i = 0; i < m; i++) {
            attempt(i, 0);
            attempt(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            attempt(0, j);
            attempt(m - 1, j);
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            attempt(i + 1, j);
            attempt(i - 1, j);
            attempt(i, j + 1);
            attempt(i, j - 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
