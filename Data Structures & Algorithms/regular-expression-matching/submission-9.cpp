class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.length(), n = p.length();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int j = n - 1; j >= 0; j--) {
            dp[j] = j < n - 1 && p[j + 1] == '*' && dp[j + 2];
        }
        for (int i = m - 1; i >= 0; i--) {
            bool tmp = dp[n];
            dp[n] = false;
            for (int j = n - 1; j >= 0; j--) {
                bool match = p[j] == '.' || s[i] == p[j];
                bool next = j == n - 1 || p[j + 1] != '*'
                    ? match && tmp
                    : dp[j + 2] || match && dp[j];
                tmp = dp[j];
                dp[j] = next;
            }
        }
        return dp[0];
    }
};
