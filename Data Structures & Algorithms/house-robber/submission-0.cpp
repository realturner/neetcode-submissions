// 12:08
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int curr = 0, pp = 0, p = 0;
        for (int x : nums) {
            pp = p;
            p = curr;
            curr = max(p, pp + x);
        }
        return curr;
    }
};
