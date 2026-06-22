// 09:55
class Solution {
public:
    vector<vector<string>> partition(string &s) {
        const int n = s.length();
        vector isPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; r++, l--) {
                isPalindrome[l][r] = true;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; r++, l--) {
                isPalindrome[l][r] = true;
            }
        }
        vector<vector<string>> ans;
        vector<string> curr;
        auto go = [&](this auto &&go, int i) -> void {
            if (i == n) {
                ans.push_back(curr);
                return;
            }
            for (int j = i; j < n; j++) {
                if (isPalindrome[i][j]) {
                    curr.push_back(s.substr(i, j - i + 1));
                    go(j + 1);
                    curr.pop_back();
                }
            }
        };
        go(0);
        return ans;
    }
};
