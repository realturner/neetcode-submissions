// 15:47
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int r = lower_bound(intervals.begin() + i + 1, intervals.end(), intervals[i][1], [](vector<int> &a, int b) {
                return a[0] < b;
            }) - intervals.begin();
            dp[i] = min(dp[i + 1] + 1, r - i - 1 + (r < n ? dp[r] : 0));
        }
        return dp[0];
    }
};
