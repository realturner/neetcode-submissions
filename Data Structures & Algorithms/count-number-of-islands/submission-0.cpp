// 10:13
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        auto go = [&](this auto &&go, int i, int j) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
                return;
            }
            grid[i][j] = '0';
            go(i + 1, j);
            go(i - 1, j);
            go(i, j + 1);
            go(i, j - 1);
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    go(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
