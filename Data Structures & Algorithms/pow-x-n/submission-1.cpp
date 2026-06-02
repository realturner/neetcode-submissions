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
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double ans = 1.0;
        while (n) {
            if (n & 1) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
