class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.length(), n = word2.length();
        vector dp(m + 1, vector<int>(n + 1, m + n));
        dp[0][0] = 0;
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
            for (int j = 1; j <= n; j++) {
                dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1]
                    : min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
        return dp[m][n];
    }
};
