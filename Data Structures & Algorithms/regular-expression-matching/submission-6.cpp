// 11:06
class TrieNode {
public:
    unordered_map<char,TrieNode*> nexts;
    bool isEnd = false;
};
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.length(), n = p.length();
        vector dp(2, vector<bool>(n + 1, false));
        dp[m % 2][n] = true;
        for (int j = n - 1; j >= 0; j--) {
            dp[m % 2][j] = j < n - 1 && p[j + 1] == '*' && dp[m % 2][j + 2];
        }
        for (int i = m - 1; i >= 0; i--) {
            auto &curr = dp[i % 2], &prev = dp[1 - i % 2];
            curr[n] = false;
            for (int j = n - 1; j >= 0; j--) {
                bool match = p[j] == '.' || s[i] == p[j];
                curr[j] = j == n - 1 || p[j + 1] != '*'
                    ? match && prev[j + 1]
                    : curr[j + 2] || match && prev[j];
            }
        }
        return dp[0][0];
        // vector dp(m + 1, vector<char>(n + 1, -1));
        // auto go = [&](this auto &&go, int i, int j) -> bool {
        //     if (j == n) {
        //         return i == m;
        //     }
        //     auto &ans = dp[i][j];
        //     if (ans != -1) {
        //         return ans;
        //     }
        //     bool match = i < m && (p[j] == '.' || s[i] == p[j]);
        //     return ans = j == n - 1 || p[j + 1] != '*'
        //         ? match && go(i + 1, j + 1)
        //         : go(i, j + 2) || match && go(i + 1, j);
        // };
        // return go(0, 0);
    }
};
