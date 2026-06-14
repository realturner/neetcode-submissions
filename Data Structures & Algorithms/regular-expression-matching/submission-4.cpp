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
        vector dp(m + 1, vector<char>(n + 1, -1));
        auto go = [&](this auto &&go, int i, int j) -> bool {
            if (j == n) {
                return i == m;
            }
            auto &ans = dp[i][j];
            if (ans != -1) {
                return ans;
            }
            if (j == n - 1 || p[j + 1] != '*') {
                return ans = i < m && (p[j] == '.' || s[i] == p[j]) && go(i + 1, j + 1);
            }
            // p[j + 1] == '*'
            return ans = go(i, j + 2) || i < m && (p[j] == '.' || s[i] == p[j]) && go(i + 1, j);
        };
        return go(0, 0);
    }
};
