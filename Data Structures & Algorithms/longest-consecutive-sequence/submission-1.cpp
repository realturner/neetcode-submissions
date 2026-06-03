// 22:26
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> x(nums.begin(), nums.end());
        int ans = 0;
        for (auto y : nums) {
            if (x.count(y - 1) == 0) {
                int curr = 1;
                for (int i = y + 1; x.count(i); i++) {
                    curr++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
