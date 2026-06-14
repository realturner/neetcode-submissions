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
        auto go = [&](this auto &&go, int i, int j) -> bool {
            if (j == n) {
                return i == m;
            }
            if (j == n - 1 || p[j + 1] != '*') {
                return i < m && (p[j] == '.' || s[i] == p[j]) && go(i + 1, j + 1);
            }
            // p[j + 1] == '*'
            if (go(i, j + 2)) {
                return true;
            }
            for (int k = i; k < m; k++) {
                if (p[j] != '.' && s[k] != p[j]) {
                    break;
                }
                if (go(k + 1, j + 2)) {
                    return true;
                }
            }
            return false;
        };
        return go(0, 0);
    }
};
