// 15:38
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int step = 1, reach = nums[0], next = 0;
        for (int i = 1; i < n; i++) {
            if (i > reach) {
                step++;
                reach = next;
            }
            next = max(next, i + nums[i]);
        }
        return step;
    }
};
