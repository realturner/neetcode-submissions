// 17:05
class Solution {
public:
    int numDecodings(string s) {
        const int n = s.length();
        int ans = s[0] == '0' ? 0 : 1;
        for (int i = 1, pp = 0, p = 1; i < n; i++) {
            pp = p;
            p = ans;
            bool canp = s[i] != '0';
            bool canpp = s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26;
            ans = (canp ? p : 0) + (canpp ? pp : 0);
        }
        return ans;
    }
};
