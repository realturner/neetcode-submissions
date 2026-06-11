class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, w * h);
            }
            st.push(i);
        }
        return ans;
    }
};
