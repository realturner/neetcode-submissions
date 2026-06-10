// 11:55
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0], a = nums[0], b = nums[0];
        for (int i = 1; i < n; i++) {
            int nextA = min({a * nums[i], b * nums[i], nums[i]});
            int nextB = max({a * nums[i], b * nums[i], nums[i]});
            ans = max(ans, nextB);
            a = nextA;
            b = nextB;
        }
        return ans;
    }
};
