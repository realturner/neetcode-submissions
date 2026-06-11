// 10:31
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size(), n = heights[0].size();
        vector ga(m, vector<bool>(n, false)), gb(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        auto attempt = [&](int i, int j, int h, vector<vector<bool>> &grid) {
            if (i >= 0 && i < m && j >= 0 && j < n && !grid[i][j] && heights[i][j] >= h) {
                grid[i][j] = true;
                q.push({i, j});
            }
        };
        auto digest = [&](vector<vector<bool>> &grid) {
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                int h = heights[i][j];
                attempt(i + 1, j, h, grid);
                attempt(i - 1, j, h, grid);
                attempt(i, j + 1, h, grid);
                attempt(i, j - 1, h, grid);
            }
        };
        for (int j = 0; j < n; j++) {
            attempt(0, j, 0, ga);
        }
        for (int i = 1; i < m; i++) {
            attempt(i, 0, 0, ga);
        }
        digest(ga);
        for (int i = 0; i < m - 1; i++) {
            attempt(i, n - 1, 0, gb);
        }
        for (int j = 0; j < n; j++) {
            attempt(m - 1, j, 0, gb);
        }
        digest(gb);
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
