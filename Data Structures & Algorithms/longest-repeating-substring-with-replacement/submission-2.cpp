// 21:29
class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.length();
        int ans = 0;
        vector<int> counts(26, 0);
        for (int i = 0, j = 0, maxf = 0; j < n; j++) {
            maxf = max(maxf, ++counts[s[j] - 'A']);
            while (j - i + 1 - maxf > k) {
                counts[s[i++] - 'A']--;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
