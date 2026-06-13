// 17:33
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.length(), n = word2.length();
        vector dp(2, vector<int>(n + 1));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            auto &curr = dp[i % 2], &prev = dp[1 - i % 2];
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                curr[j] = word1[i - 1] == word2[j - 1] ? prev[j - 1]
                    : min({curr[j - 1], prev[j], prev[j - 1]}) + 1;
            }
        }
        return dp[m % 2][n];
    }
};
