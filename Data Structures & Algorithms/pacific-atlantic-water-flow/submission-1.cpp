// 10:31
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size(), n = heights[0].size();
        auto work = [&](function<void(queue<pair<int,int>>&,vector<vector<bool>>&)> init) {
            vector grid(m, vector<bool>(n, false));
            queue<pair<int,int>> q;
            init(q, grid);
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                int h = heights[i][j];
                for (int di = 0, dj = 1, r = 0; r < 4; r++) {
                    swap(di, dj);
                    di = -di;
                    int ii = i + di, jj = j + dj;
                    if (ii >= 0 && ii < m && jj >= 0 && jj < n && !grid[ii][jj] && heights[ii][jj] >= h) {
                        q.push({ii, jj});
                        grid[ii][jj] = true;
                    }
                }
            }
            return grid;
        };
        auto ga = work([&](queue<pair<int,int>> &q, vector<vector<bool>> &grid) {
            for (int j = 0; j < n; j++) {
                q.push({0, j});
                grid[0][j] = true;
            }
            for (int i = 1; i < m; i++) {
                q.push({i, 0});
                grid[i][0] = true;
            }
        });
        auto gb = work([&](queue<pair<int,int>> &q, vector<vector<bool>> &grid) {
            for (int i = 0; i < m - 1; i++) {
                q.push({i, n - 1});
                grid[i][n - 1] = true;
            }
            for (int j = 0; j < n; j++) {
                q.push({m - 1, j});
                grid[m - 1][j] = true;
            }
        });
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ga[i][j] && gb[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
