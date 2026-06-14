// 10:45
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        for (int i = 0, j = 0, di = 0, dj = 1; ans.size() < m * n; i += di, j += dj) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            int ii = i + di, jj = j + dj;
            if (ii < 0 || ii >= m || jj < 0 || jj >= n || matrix[ii][jj] == INT_MIN) {
                swap(di, dj);
                dj = -dj;
            }
        }
        return ans;
    }
};
