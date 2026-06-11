// 14:51
class Solution {
public:
    bool checkValidString(string &s) {
        const int n = s.length();
        vector dp(n, vector<char>(n + 1, -1));
        auto go = [&](this auto &&go, int i, int curr) -> bool {
            if (curr < 0) {
                return false;
            }
            while (i < n && s[i] != '*') {
                curr += s[i++] == '(' ? 1 : -1;
                if (curr < 0) {
                    return false;
                }
            }
            if (i == n) {
                return curr == 0;
            }
            if (dp[i][curr] == -1) {
                dp[i][curr] = go(i + 1, curr + 1) || go(i + 1, curr) || go(i + 1, curr - 1) ? 1 : 0;
            }
            return dp[i][curr];
        };
        return go(0, 0);
    }
};
