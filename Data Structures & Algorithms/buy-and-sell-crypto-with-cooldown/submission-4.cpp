class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        /*
            dp[i] := optimal profit for prices[0..i]
                = max(dp[i - 1], prices[i] + hold[i - 1])
                => dp[i] = 0 for i <= 0
            hold[i] := optimal if buys prices[j] for j <= i
                = max(hold[i - 1], -prices[i] + dp[i - 2])
                => hold[1] = -prices[0]

            prices: [ 1, 3, 4, 0, 4]
            dp:     [ 0, 2]
            hold:   [-1]
        */
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n), hold(n);
        dp[0] = 0;
        hold[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], prices[i] + hold[i - 1]);
            hold[i] = max(hold[i - 1], -prices[i] + (i >= 2 ? dp[i - 2] : 0));
        }
        return dp[n - 1];
    }
};
