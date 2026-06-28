// 09:04
class Solution {
    vector<pair<int,int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    };
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        for (int step = 1; !q.empty(); step++) {
            for (int k = q.size(); k > 0; k--) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [di, dj] : dirs) {
                    int ii = i + di, jj = j + dj;
                    if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == INT_MAX) {
                        grid[ii][jj] = step;
                        q.push({ii, jj});
                    }
                }
            }
        }
    }
};
