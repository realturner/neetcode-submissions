// 12:32
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        const int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums) {
            for (int i = target; i >= x; i--) {
                if (dp[i - x]) {
                    dp[i] = true;
                }
            }
        }
        return dp[target];
    }
};
