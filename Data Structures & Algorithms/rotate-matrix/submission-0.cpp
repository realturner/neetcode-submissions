// 11:13
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tmp = matrix[i][j];
                for (int ii = i, jj = j, r = 0; r < 4; r++) {
                    ii = n - 1 - ii;
                    swap(ii, jj);
                    swap(tmp, matrix[ii][jj]);
                }
            }
        }
    }
};

/*
+-------------
|         *
|  *
|          
| 
|     *
|
+--------------

*/