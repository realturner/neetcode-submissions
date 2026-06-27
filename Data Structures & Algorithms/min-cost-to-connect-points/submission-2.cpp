class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        auto w = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        vector<int> dist(n, INT_MAX);
        vector<bool> seen(n, false);
        int ans = 0;
        dist[0] = 0;
        for (int remain = n - 1, u = 0; remain > 0; remain--) {
            seen[u] = true;
            int uu = -1;
            for (int v = 0; v < n; v++) {
                if (seen[v]) {
                    continue;
                }
                dist[v] = min(dist[v], w(u, v));
                if (uu == -1 || dist[uu] > dist[v]) {
                    uu = v;
                }
            }
            ans += dist[uu];
            u = uu;
        }
        return ans;
    }
};
