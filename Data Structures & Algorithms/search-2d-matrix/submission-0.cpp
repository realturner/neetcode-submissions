// 09:06
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            int i = mid / n, j = mid % n;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return matrix[l / n][l % n] == target;
    }
};
