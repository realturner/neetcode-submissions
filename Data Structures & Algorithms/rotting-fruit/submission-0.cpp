// 20:43
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int remain = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    remain++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (remain == 0) {
            return 0;
        }
        for (int step = 0; !q.empty(); step++) {
            for (int k = q.size(); k > 0; k--) {
                auto [i, j] = q.front();
                q.pop();
                for (int di = 0, dj = 1, r = 0; r < 4; r++, swap(di, dj), di = -di) {
                    int ii = i + di, jj = j + dj;
                    if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == 1) {
                        if (--remain == 0) {
                            return step + 1;
                        }
                        grid[ii][jj] = 2;
                        q.push({ii, jj});
                    }
                }
            }
        }
        return -1;
    }
};
