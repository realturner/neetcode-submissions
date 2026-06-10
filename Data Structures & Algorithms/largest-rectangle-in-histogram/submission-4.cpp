// 17:46
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // heights.push_back(0);
        const int n = heights.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int curr = i < n ? heights[i] : 0;
            while (!st.empty() && heights[st.top()] >= curr) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        return ans;
    }
};
