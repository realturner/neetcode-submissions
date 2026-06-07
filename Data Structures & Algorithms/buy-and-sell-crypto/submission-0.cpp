// 14:25
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int ans = 0;
        for (int i = 1, pMin = prices[0]; i < n; i++) {
            ans = max(ans, prices[i] - pMin);
            pMin = min(pMin, prices[i]);
        }
        return ans;
    }
};
