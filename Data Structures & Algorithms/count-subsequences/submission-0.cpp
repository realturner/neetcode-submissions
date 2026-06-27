// 09:05
class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.length(), n = t.length();
        vector dp(2, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            auto &curr = dp[i % 2], &prev = dp[1 - i % 2];
            curr[0] = 1;
            for (int j = 1; j <= n; j++) {
                curr[j] = prev[j];
                if (s[i - 1] == t[j - 1]) {
                    curr[j] += prev[j - 1];
                }
            }
        }
        return dp[m % 2][n];
    }
};
