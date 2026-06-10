// 11:55
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        for (int i = 0, acc = 0; i < n; i++) {
            acc = acc == 0 ? nums[i] : acc * nums[i];
            ans = max(ans, acc);
        }
        for (int i = n - 1, acc = 0; i >= 0; i--) {
            acc = acc == 0 ? nums[i] : acc * nums[i];
            ans = max(ans, acc);
        }
        return ans;
    }
};
