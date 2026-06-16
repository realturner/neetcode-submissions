// 10:08
class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans++;
            for (int l = i - 1, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                ans++;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                ans++;
            }
        }
        return ans;
    }
};
