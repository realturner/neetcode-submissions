// 14:52
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int minPre = min(0, nums[0]), curr = nums[0], ans = nums[0];
        for (int i = 1; i < n; i++) {
            curr += nums[i];
            ans = max(ans, curr - minPre);
            minPre = min(minPre, curr);
        }
        return ans;
    }
};
