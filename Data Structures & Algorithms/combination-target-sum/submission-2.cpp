// 17:17
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        int sum = 0;
        auto go = [&](this auto &&go, int i) -> void {
            if (sum == target) {
                ans.push_back(curr);
                return;
            }
            for (int j = i; j < n && nums[j] + sum <= target; j++) {
                curr.push_back(nums[j]);
                sum += nums[j];
                go(j);
                sum -= nums[j];
                curr.pop_back();
            }
        };
        go(0);
        return ans;
    }
};
