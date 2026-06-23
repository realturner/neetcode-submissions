// 10:44
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        auto go = [&](this auto &&go, int i, int j) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
                return 0;
            }
            grid[i][j] = 0;
            return 1 + go(i + 1, j) + go(i - 1, j) + go(i, j + 1) + go(i, j - 1);
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans = max(ans, go(i, j));
                }
            }
        }
        return ans;
    }
};
