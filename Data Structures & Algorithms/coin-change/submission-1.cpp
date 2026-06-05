// 20:59
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < amount; i++) {
            if (dp[i] >= 0) {
                for (int x : coins) {
                    if (0LL + i + x <= amount && (dp[i + x] == -1 || dp[i + x] > dp[i] + 1)) {
                        dp[i + x] = dp[i] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};
