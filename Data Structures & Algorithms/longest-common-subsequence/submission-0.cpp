// 10:34
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.length(), n = text2.length();
        vector dp(2, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            auto &curr = dp[i % 2], &prev = dp[1 - i % 2];
            for (int j = 1; j <= n; j++) {
                curr[j] = text1[i - 1] == text2[j - 1]
                    ? prev[j - 1] + 1
                    : max(curr[j - 1], prev[j]);
            }
        }
        return dp[m % 2][n];
    }
};
