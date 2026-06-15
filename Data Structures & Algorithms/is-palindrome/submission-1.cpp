// 10:16
class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.length();
        auto attempt = [&](char ch) -> char {
            return ch >= 'A' && ch <= 'Z' ? ch
                : ch >= 'a' && ch <= 'z' ? ch - 'a' + 'A'
                : ch >= '0' && ch <= '9' ? ch
                : '\0';
        };
        for (int i = 0, j = n - 1; i < j; ) {
            auto a = attempt(s[i]), b = attempt(s[j]);
            if (!a) {
                i++;
                continue;
            } else if (!b) {
                j--;
                continue;
            }
            if (a != b) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
