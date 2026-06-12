class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0, r = n - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
