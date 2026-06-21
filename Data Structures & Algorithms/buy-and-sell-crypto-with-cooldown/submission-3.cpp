// 10:07
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int pp = 0, p = 0, ans = 0, hold = -prices[0];
        for (int i = 1; i < n; i++) {
            ans = max(prices[i] + hold, p);
            hold = max(hold, pp - prices[i]);
            pp = p;
            p = ans;
        }
        return ans;
    }
};
