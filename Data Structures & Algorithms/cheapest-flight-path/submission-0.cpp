// 09:14
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector dist(n, vector<int>(k + 2, INT_MAX));
        dist[src] = {k + 2, 0};
        using Cand = tuple<int,int,int>;
        priority_queue<Cand, vector<Cand>, greater<>> pq;
        pq.push({0, 0, src});
        while (!pq.empty()) {
            auto [d, jump, u] = pq.top();
            pq.pop();
            if (jump > k + 1 || d > dist[u][jump]) {
                continue;
            }
            if (u == dst) {
                return d;
            }
            if (jump == k + 1) {
                continue;
            }
            for (auto &[v, w] : adj[u]) {
                if (dist[v][jump + 1] > d + w) {
                    dist[v][jump + 1] = d + w;
                    pq.push({d + w, jump + 1, v});
                }
            }
        }
        return -1;
    }
};
