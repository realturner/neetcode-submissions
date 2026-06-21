// 10:07
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<int> hold(n, 0), profit(n, 0);
        for (int i = 0; i < n; i++) {
            hold[i] = -prices[i];
            if (i > 0) {
                hold[i] = max(hold[i], hold[i - 1]);
            }
            if (i >= 2) {
                hold[i] = max(hold[i], profit[i - 2] - prices[i]);
            }
            if (i > 0) {
                profit[i] = max({0, prices[i] + hold[i - 1], profit[i - 1]});
            }
        }
        return profit[n - 1];
    }
};
