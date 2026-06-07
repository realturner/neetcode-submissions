// 14:33
class Solution {
public:
    string multiply(string num1, string num2) {
        const int m = num1.length(), n = num2.length();
        vector<int> tmp(m + n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i + j] += (num1[m - i - 1] - '0') * (num2[n - j - 1] - '0');
            }
        }
        int limit = 0;
        for (int i = 0, carry = 0; i < m + n; i++) {
            carry += tmp[i];
            tmp[i] = carry % 10;
            carry /= 10;
            if (tmp[i]) {
                limit = i;
            }
        }
        if (limit == 0 && tmp[0] == 0) {
            return "0";
        }
        string ans = "";
        for (int i = 0; i <= limit; i++) {
            ans += tmp[i] + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
