class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        for (int i = 0, curr = 1; i < n; i++) {
            curr = curr == 0 ? nums[i] : nums[i] * curr;
            ans = max(ans, curr);
        }
        for (int i = n - 1, curr = 1; i >= 0; i--) {
            curr = curr == 0 ? nums[i] : nums[i] * curr;
            ans = max(ans, curr);
        }
        return ans;
    }
};
