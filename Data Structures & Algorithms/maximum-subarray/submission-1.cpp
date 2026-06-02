// 15:02
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for (int x : nums) {
            sum = max(sum, 0) + x;
            ans = max(ans, sum);
        }
        return ans;
    }
};
