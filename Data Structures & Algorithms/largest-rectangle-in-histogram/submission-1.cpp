// 17:46
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        const int n = heights.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int p = st.top(), h = heights[p], r = i - 1, l;
                st.pop();
                l = st.empty() ? 0 : st.top() + 1;
                cout << l << ' ' << p << "(" << h << ") " << r << endl;
                ans = max(ans, h * (r - l + 1));
            }
            if (st.empty() || heights[i] != heights[i - 1]) {
                st.push(i);
            }
        }
        return ans;
    }
};
