// 09:09
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        int p = 0, q = 0;
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if (r - l > q - p) {
                    p = l;
                    q = r;
                }
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if (r - l > q - p) {
                    p = l;
                    q = r;
                }
            }
        }
        return s.substr(p, q - p + 1);
    }
};
