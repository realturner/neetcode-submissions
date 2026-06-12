class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0;
        for (char ch : s) {
            switch (ch) {
                case '(': l++; r++; break;
                case ')': l--; r--; break;
                default: l--; r++;
            }
            if (r < 0) {
                return false;
            } else if (l < 0) {
                l = 0;
            }
        }
        return l == 0;
    }
};
