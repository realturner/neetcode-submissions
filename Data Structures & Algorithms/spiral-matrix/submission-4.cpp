class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<pair<int,int>> dirs = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        vector<int> ans;
        for (int i = 0, j = 0, w = n - 1, h = m - 1, r = 0; ans.size() < m * n; ) {
            ans.push_back(matrix[i][j]);
            for (int k = 0; k < w; k++) {
                i += dirs[r].first;
                j += dirs[r].second;
                ans.push_back(matrix[i][j]);
            }
            w--;
            r = (r + 1) % 4;
            for (int k = 0; k < h; k++) {
                i += dirs[r].first;
                j += dirs[r].second;
                ans.push_back(matrix[i][j]);
            }
            h--;
            r = (r + 1) % 4;
            i += dirs[r].first;
            j += dirs[r].second;
        }
        return ans;
    }
};
