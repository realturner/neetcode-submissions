// 20:58
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        for (int i = 1, pp = 0, p = 0, curr; i < n; i++) {
            curr = max(pp + nums[i], p);
            ans = max(ans, curr);
            pp = p;
            p = curr;
        }
        for (int i = 0, pp = 0, p = 0, curr; i < n - 1; i++) {
            curr = max(pp + nums[i], p);
            ans = max(ans, curr);
            pp = p;
            p = curr;
        }
        return ans;
    }
};
