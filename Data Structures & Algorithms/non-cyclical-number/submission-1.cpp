// 14:35
class Solution {
    int next(int x) {
        int ans = 0;
        while (x) {
            ans += (x % 10) * (x % 10);
            x /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int i = n, j = next(n);
        while (i != j) {
            j = next(next(j));
            i = next(i);
        }
        return i == 1;
    }
};
