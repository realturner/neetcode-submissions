// 09:26
class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        const int m = s1.length(), n = s2.length();
        if (s3.length() != m + n) {
            return false;
        }
        vector dp(2, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (int i = 1; i <= m; i++) {
            auto &curr = dp[i % 2], &prev = dp[1 - i % 2];
            curr[0] = prev[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; j++) {
                curr[j] = 
                    (curr[j - 1] && s3[i + j - 1] == s2[j - 1]) ||
                    (prev[j] && s3[i + j - 1] == s1[i - 1]);
            }
        }
        return dp[m % 2][n];
    }
};
