// 10:18
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        int r = cost[n - 2], rr = cost[n - 1];
        for (int i = n - 3, tmp; i >= 0; i--) {
            tmp = cost[i] + min(r, rr);
            rr = r;
            r = tmp;
        }
        return min(r, rr);
    }
};
