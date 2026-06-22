class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        const int n = s.length();
        vector<int> counts(26, 0);
        for (char ch : s) {
            counts[ch - 'a']++;
        }
        for (char ch : t) {
            counts[ch - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
