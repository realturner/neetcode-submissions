class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<tuple<int,int,int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({w, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> roots(n);
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }
        auto find = [&](this auto &&find, int x) -> int {
            if (roots[x] != x) {
                return roots[x] = find(roots[x]);
            }
            return x;
        };
        int remain = n - 1, ans = 0;
        for (auto [w, u, v] : edges) {
            int x = find(u), y = find(v);
            if (x != y) {
                roots[x] = y;
                ans += w;
                if (--remain == 0) {
                    return ans;
                }
            }
        }
        return 0;
    }
};
