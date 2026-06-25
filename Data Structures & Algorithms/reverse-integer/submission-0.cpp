// 08:45
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            bool isOverflow = x > 0
                ? ans > INT_MAX / 10 || INT_MAX - 10 * ans < x % 10
                : ans < INT_MIN / 10 || INT_MIN - 10 * ans > x % 10;
            if (isOverflow) {
                return 0;
            }
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
