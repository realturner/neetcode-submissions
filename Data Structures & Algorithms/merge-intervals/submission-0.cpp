class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int p = intervals[0][0], q = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                ans.push_back({p, q});
            } else if (intervals[i][0] > q) {
                ans.push_back({p, q});
                p = intervals[i][0];
                q = intervals[i][1];
            } else {
                q = max(q, intervals[i][1]);
            }
        }
        return ans;
    }
};
