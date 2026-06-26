class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) {
            nums2.swap(nums1);
        }
        const int m = nums1.size(), n = nums2.size();
        int l = 0, r = m, mid;
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = (m + n) / 2 - i;
            int l1 = i > 0 ? nums1[i - 1] : INT_MIN;
            int r1 = i < m ? nums1[i] : INT_MAX;
            int l2 = j > 0 ? nums2[j - 1] : INT_MIN;
            int r2 = j < n ? nums2[j] : INT_MAX;
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2) {
                    return min(r1, r2);
                }
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return NAN;
    }
};
