// 19:48
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        for (int x : nums) {
            int i = lower_bound(nums.begin(), nums.begin() + len, x) - nums.begin();
            if (i == len) {
                nums[len++] = x;
            } else {
                nums[i] = x;
            }
        }
        return len;
    }
};
