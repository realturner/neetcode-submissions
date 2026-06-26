// 10:57
class Solution {
public:
    string minWindow(string s, string t) {
        const int m = s.length();
        vector<int> counts(256);
        int remain = 0;
        for (char ch : t) {
            if (counts[ch]-- == 0) {
                remain++;
            }
        }
        int lo = 0, hi = 0;
        for (int l = 0, r = 0; r < m; r++) {
            if (++counts[s[r]] == 0) {
                --remain;
            }
            while (l <= r && remain == 0) {
                // [l, r + 1) is good
                if (lo == hi || hi - lo > r - l + 1) {
                    lo = l;
                    hi = r + 1;
                }
                if (--counts[s[l++]] < 0) {
                    remain++;
                }
            }
        }
        if (hi > lo) {
            return s.substr(lo, hi - lo);
        }
        return "";
    }
};
