// 14:51
class Solution {
public:
    bool checkValidString(string &s) {
        const int n = s.length();
        vector seen(n, vector<bool>(n + 1, false));
        auto go = [&](this auto &&go, int i, int curr) -> bool {
            if (curr < 0) {
                return false;
            }
            while (i < n && s[i] != '*') {
                curr += s[i++] == '(' ? 1 : -1;
                if (curr < 0) {
                    return false;
                }
            }
            if (i == n) {
                return curr == 0;
            }
            if (seen[i][curr]) {
                return false;
            }
            seen[i][curr] = true;
            return go(i + 1, curr + 1) || go(i + 1, curr) || go(i + 1, curr - 1) ? 1 : 0;
        };
        return go(0, 0);
    }
};
