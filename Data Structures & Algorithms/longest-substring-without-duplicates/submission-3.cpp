#include<cstring>
class Solution {
    int counts[256];
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        // vector<int> counts(26);
        memset(counts, 0, sizeof(counts));
        int l = 0, r = 0, dupCounts = 0, ans = 0;
        while (r < n) {
            if (++counts[s[r++]] > 1) {
                dupCounts++;
            }
            while (dupCounts > 0) {
                if (--counts[s[l++]] == 1) {
                    --dupCounts;
                }
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
