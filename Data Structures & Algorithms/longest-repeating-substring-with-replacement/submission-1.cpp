// 21:29
class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.length();
        int i, j, x, ans = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            for (i = 0, j = 0, x = 0; j < n; j++) {
                x += s[j] == c ? 0 : 1;
                if (x > k) {
                    x -= s[i++] == c ? 0 : 1;
                }
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
