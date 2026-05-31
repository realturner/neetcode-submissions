// 21:10
class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        const int m = s1.length(), n = s2.length();
        if (n < m) {
            return false;
        }
        vector<int> a(26, 0), b(26, 0);
        for (int i = 0; i < m; i++) {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }
        int matchCount = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i] == b[i]) {
                matchCount++;
            }
        }
        if (matchCount == 26) {
            return true;
        }
        for (int i = m; i < n; i++) {
            char incr = s2[i] - 'a', desc = s2[i - m] - 'a';
            if (incr == desc) {
                continue;
            }
            matchCount += b[incr] == a[incr] ? -1 : b[incr] == a[incr] - 1 ? 1 : 0;
            b[incr]++;
            matchCount += b[desc] == a[desc] ? -1 : b[desc] == a[desc] + 1 ? 1 : 0;
            b[desc]--;
            if (matchCount == 26) {
                return true;
            }
        }
        return false;
    }
};
