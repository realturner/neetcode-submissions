// 19:13
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int ans = 0;
        for (int i = 0, j = n - 1, l = height[0], r = height[n - 1]; i < j; ) {
            if (l <= r) {
                l = max(l, height[++i]);
                ans += l - height[i];
            } else {
                r = max(r, height[--j]);
                ans += r - height[j];
            }
        }
        return ans;
    }
};
