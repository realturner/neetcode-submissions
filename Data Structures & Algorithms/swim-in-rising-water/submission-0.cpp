// 10:09
class Solution {
    vector<pair<int,int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> roots(n * n);
        for (int i = n * n - 1; i >= 0; i--) {
            roots[i] = i;
        }
        auto find = [&](this auto &&find, int x) -> int {
            if (roots[x] != x) {
                return roots[x] = find(roots[x]);
            }
            return x;
        };
        vector<int> indices(n * n);
        for (int i = n * n - 1; i >= 0; i--) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return grid[i / n][i % n] < grid[j / n][j % n];
        });
        const int target = n * n - 1;
        for (int step = 0; step <= target; step++) {
            int i = indices[step] / n, j = indices[step] % n;
            // cout << i << ' ' << j << ' ' << grid[i][j] << endl;
            auto x = find(i * n + j);
            for (auto [di, dj] : dirs) {
                int ii = i + di, jj = j + dj;
                if (ii >= 0 && ii < n && jj >= 0 && jj < n && grid[ii][jj] <= grid[i][j]) {
                    // cout << ' ' << ii << ' ' << jj << ' ' << grid[ii][jj] << endl;
                    auto y = find(ii * n + jj);
                    if (x != y) {
                        // cout << "  join" << endl;
                        roots[y] = x;
                    }
                }
            }
            if (find(0) == find(target)) {
                return step;
            }
        }
        return -1;
    }
};
