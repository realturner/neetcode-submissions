// 22:26
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> x(nums.begin(), nums.end());
        int ans = 0;
        while (!x.empty()) {
            int curr = 1;
            auto y = *x.begin();
            x.erase(y);
            for (int i = y + 1; x.count(i); i++) {
                x.erase(i);
                curr++;
            }
            for (int i = y - 1; x.count(i); i--) {
                x.erase(i);
                curr++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
