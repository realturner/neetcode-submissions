// 12:15
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> dp = {{0, 1}};
        for (int x : nums) {
            unordered_map<int,int> next;
            for (auto &[v, cnt] : dp) {
                next[v + x] += cnt;
                next[v - x] += cnt;
            }
            dp = move(next);
        }
        return dp[target];
    }
};
