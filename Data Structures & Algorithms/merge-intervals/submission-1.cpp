class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto &seg : intervals) {
            if (ans.empty() || ans.back()[1] < seg[0]) {
                ans.push_back(seg);
            } else {
                ans.back()[1] = max(ans.back()[1], seg[1]);
            }
        }
        return ans;
    }
};
