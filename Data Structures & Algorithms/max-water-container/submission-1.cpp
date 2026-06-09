// 12:11
class Solution {
public:
    int maxArea(vector<int>& heights) {
        const int n = heights.size();
        int ans = 0;
        for (int i = 0, j = n - 1; i < j; ) {
            if (heights[i] <= heights[j]) {
                ans = max(ans, heights[i] * (j - i));
                i++;
            } else {
                ans = max(ans, heights[j] * (j - i));
                j--;
            }
        }
        return ans;
    }
};
