// 10:00
class Solution {
public:
    int findMin(vector<int> &nums) {
        const int n = nums.size();
        int l = 0, r = n - 1, mid;
        while (l < r) {
            // cout << l << ' ' << r << endl;
            if (nums[l] < nums[r]) {
                return nums[l];
            }
            mid = l + (r - l) / 2;
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
