// 08:55
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        multiset<int> curr;
        for (int i = 0; i < k; i++) {
            curr.insert(nums[i]);
        }
        vector<int> ans = { *curr.rbegin() };
        for (int i = k; i < n; i++) {
            curr.insert(nums[i]);
            curr.erase(curr.find(nums[i - k]));
            ans.push_back(*curr.rbegin());
        }
        return ans;
    }
};
