#include<cstring>
class Solution {
    int counts[256];
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        memset(counts, 0, sizeof(counts));
        int l = 0, r = 0, ans = 0;
        while (r < n) {
            if (++counts[s[r]] > 1) {
                while (counts[s[r]] > 1) {
                    --counts[s[l++]];
                }
            }
            r++;
            ans = max(ans, r - l);
        }
        return ans;
    }
};
