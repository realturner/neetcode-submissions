// 11:18
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int i = 1; i <= n - 1; i++) {
            ans = ans * (m + n - i - 1) / i;
        }
        return ans;
    }
};
