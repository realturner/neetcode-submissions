class Solution {
public:
    bool checkValidString(string &s) {
        int a = 0, b = 0;
        for (char ch : s) {
            switch (ch) {
                case '(': a++; b++; break;
                case ')': a--; b--; break;
                default: a--; b++;
            }
            if (b < 0) {
                return false;
            }
            a = max(a, 0);
        }
        return a == 0;
    }
};
