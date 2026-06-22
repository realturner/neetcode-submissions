// 09:12
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int m = intervals.size(), n = queries.size();
        sort(intervals.begin(), intervals.end());
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> ans(n, -1);
        int i = 0;
        for (int p = 0; p < n; p++) {
            int &j = indices[p], &q = queries[j];
            while (i < m && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans[j] = pq.top().first;
            }
        }
        return ans;
    }
};
