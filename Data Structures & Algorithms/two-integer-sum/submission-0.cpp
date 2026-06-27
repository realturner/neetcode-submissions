// 10:00
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        unordered_map<int,int> valFirstIdx;
        for (int i = n - 1; i >= 0; i--) {
            auto it = valFirstIdx.find(target - nums[i]);
            if (it != valFirstIdx.end()) {
                return {i, it->second};
            }
            valFirstIdx[nums[i]] = i;
        }
        return {};
    }
};
