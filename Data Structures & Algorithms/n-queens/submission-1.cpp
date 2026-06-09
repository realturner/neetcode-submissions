// 10:53
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n, string(n, '.'));
        vector<vector<string>> ans;
        int usedCol = 0, usedDiagL = 0, usedDiagR = 0;
        auto go = [&](this auto &&go, int i) -> void {
            if (i == n) {
                ans.push_back(curr);
                return;
            }
            for (int j = 0; j < n; j++) {
                int colMask = 1 << j, diagLMask = 1 << i - j + n, diagRMask = 1 << i + j;
                if ((usedCol & colMask) || (usedDiagL & diagLMask) || (usedDiagR & diagRMask)) {
                    continue;
                }
                usedCol ^= colMask;
                usedDiagL ^= diagLMask;
                usedDiagR ^= diagRMask;
                curr[i][j] = 'Q';
                go(i + 1);
                curr[i][j] = '.';
                usedCol ^= colMask;
                usedDiagL ^= diagLMask;
                usedDiagR ^= diagRMask;
            }
        };
        go(0);
        return ans;
    }
};
