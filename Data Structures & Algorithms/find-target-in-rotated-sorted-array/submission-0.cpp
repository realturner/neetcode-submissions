// 10:48
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0, r = n - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[l] < nums[r]) {
                if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target >= nums[l] || target <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};
