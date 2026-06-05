// 19:13
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int ans = 0;
        for (int i = 0, j = n - 1, l = height[0], r = height[n - 1]; i < j; ) {
            if (l <= r) {
                ans += max(l - height[++i], 0);
                l = max(l, height[i]);
            } else {
                ans += max(r - height[--j], 0);
                r = max(r, height[j]);
            }
        }
        return ans;
    }
};
