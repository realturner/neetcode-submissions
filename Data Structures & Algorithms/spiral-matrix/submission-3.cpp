class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<pair<int,int>> dirs = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        vector<int> ans;
        for (int i = 0, j = 0, remain = m * n, r = 0; remain > 0; remain--) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            int ii = i + dirs[r].first, jj = j + dirs[r].second;
            if (ii < 0 || ii >= m || jj < 0 || jj >= n || matrix[ii][jj] == INT_MIN) {
                r = (r + 1) % 4;
                ii = i + dirs[r].first;
                jj = j + dirs[r].second;
            }
            i = ii;
            j = jj;
        }
        return ans;
    }
};
