// 21:10
class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        const int m = s1.length(), n = s2.length();
        if (n < m) {
            return false;
        }
        vector<int> a(26, 0), b(26, 0);
        for (char ch : s1) {
            a[ch - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            b[s2[i] - 'a']++;
        }
        if (a == b) {
            return true;
        }
        for (int i = m; i < n; i++) {
            b[s2[i] - 'a']++;
            b[s2[i - m] - 'a']--;
            if (a == b) {
                return true;
            }
        }
        return false;
    }
};
