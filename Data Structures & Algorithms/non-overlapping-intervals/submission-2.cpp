// 15:47
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        for (int i = 0, p = intervals[0][0]; i < n; i++) {
            if (p <= intervals[i][0]) {
                p = intervals[i][1];
            } else {
                ans++;
                p = min(p, intervals[i][1]);
            }
        }
        return ans;
    }
};
