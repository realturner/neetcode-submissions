class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.length(), n = p.length();
        /*
            dp[i][j] := s[0..i - 1] is matched on pattern p[0..j - 1]
               (-1: cache miss, 0: false, 1: true)
        */
        vector dp(m + 1, vector<char>(n + 1, -1));
        auto go = [&](this auto &&go, int i, int j) -> bool {
            // base case
            if (j == n) {
                return i == m;
            }
            // cache
            auto &ans = dp[i][j];
            if (ans != -1) {
                return ans;
            }
            bool matched = i < m && (s[i] == p[j] || p[j] == '.');
            if (j < n - 1 && p[j + 1] == '*') {
                return ans = matched && go(i + 1, j) || go(i, j + 2);
            }
            return ans = matched && go(i + 1, j + 1);
        };
        return go(0, 0);
    }
};
