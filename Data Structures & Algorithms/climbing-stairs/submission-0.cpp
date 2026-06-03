// 22:17
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int ans, a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};
