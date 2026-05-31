// 20:13
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int curr = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= curr) {
                curr = i;
            }
        }
        return curr == 0;
    }
};
