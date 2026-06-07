// 15:38
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int step = 0;
        for (int i = 0, reach = 0, next = 0; i < n; i++) {
            if (i > reach) {
                step++;
                reach = next;
            }
            next = max(next, i + nums[i]);
        }
        return step;
    }
};
