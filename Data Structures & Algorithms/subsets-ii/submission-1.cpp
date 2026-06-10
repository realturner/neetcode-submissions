// 13:07
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        auto go = [&](this auto &&go, int i) -> void {
            ans.push_back(curr);
            for (int j = i; j < n; j++) {
                if (j > i && nums[j] == nums[j - 1]) {
                    continue;
                }
                curr.push_back(nums[j]);
                go(j + 1);
                curr.pop_back();
            }
        };
        go(0);
        return ans;
    }
};
