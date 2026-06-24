// 10:19
#include <cstring>
class Solution {
    vector<pair<int,int>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
    };
    int dp[100][100];
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        auto go = [&](this auto &&go, int i, int j) -> int {
            auto &ans = dp[i][j];
            if (ans != -1) {
                return ans;
            }
            ans = 1;
            for (auto [di, dj] : dirs) {
                int ii = i + di, jj = j + dj;
                if (ii >= 0 && ii < m && jj >= 0 && jj < n && matrix[ii][jj] > matrix[i][j]) {
                    ans = max(ans, 1 + go(ii, jj));
                }
            }
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, go(i, j));
            }
        }
        return ans;
    }
};
