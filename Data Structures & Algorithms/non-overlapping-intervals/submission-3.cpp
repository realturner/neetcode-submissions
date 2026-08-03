class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int p = intervals[0][0], ans = 0;
        for (auto &interval : intervals) {
            if (interval[0] < p) {
                ans++;
                p = min(p, interval[1]);
            } else {
                p = interval[1];
            }
        }
        return ans;
    }
};
