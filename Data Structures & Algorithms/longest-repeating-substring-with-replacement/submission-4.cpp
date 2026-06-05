// 21:29
class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.length();
        int i, j, maxf;
        vector<int> counts(26, 0);
        for (i = 0, j = 0, maxf = 0; j < n; j++) {
            maxf = max(maxf, ++counts[s[j] - 'A']);
            if (j - i + 1 - maxf > k) {
                counts[s[i++] - 'A']--;
            }
        }
        return j - i;
    }
};
