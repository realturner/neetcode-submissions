// 10:41
class Solution {

public:
    double myPow(double x, int n) {
        if (x == 0) {
            return n > 0 ? 0.0 : NAN;
        }
        if (n == 0) {
            return 1.0;
        }
        double sign = x < 0 && n % 2 ? -1 : 1;
        x = abs(x);
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double base = x, ans = 1.0;
        while (n) {
            if (n & 1) {
                ans *= base;
            }
            base *= base;
            n >>= 1;
        }
        return sign * ans;
    }
};
