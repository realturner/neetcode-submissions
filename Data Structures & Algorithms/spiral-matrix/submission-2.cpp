// 11:27
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int w = n, h = m;
        for (int i = 0, j = 0, di = 0, dj = 1; ans.size() < m * n; i += di, j += dj) {
            ans.push_back(matrix[i][j]);
            for (int k = --w; k > 0; k--) {
                ans.push_back(matrix[i += di][j += dj]);
            }
            swap(di, dj);
            dj = -dj;
            for (int k = --h; k > 0; k--) {
                ans.push_back(matrix[i += di][j += dj]);
            }
            swap(di, dj);
            dj = -dj;
        }
        return ans;
    }
};
