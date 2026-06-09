// 10:53
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<int> used(n);
        auto go = [&](this auto &&go, int i) -> void {
            if (i == n) {
                ans.push_back(curr);
                return;
            }
            int ok = (1 << n) - 1;
            auto unset = [&](int x) -> void {
                if (x >= 0 && x < n) {
                    ok &= ~(1 << x);
                }
            };
            for (int j = 0; j < i; j++) {
                unset(used[j]);
                unset(used[j] + i - j);
                unset(used[j] - i + j);
            }
            for (int j = 0, mask = 1; j < n; j++, mask <<= 1) {
                if (mask & ok) {
                    used[i] = j;
                    curr[i][j] = 'Q';
                    go(i + 1);
                    curr[i][j] = '.';
                }
            }
        };
        go(0);
        return ans;
    }
};
