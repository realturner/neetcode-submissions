class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for (int i = 0 ; i < n; i++) {
            ans ^= (i + 1) ^ nums[i];
        }
        return ans;
    }
};
