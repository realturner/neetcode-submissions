// 09:14
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<tuple<int,int,int>> q;
        q.push({0, 0, src});
        while (!q.empty()) {
            auto [d, jump, u] = q.front();
            q.pop();
            if (jump > k) {
                continue;
            }
            for (auto &[v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    q.push({d + w, jump + 1, v});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
