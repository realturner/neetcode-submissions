// 11:56
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjs(n);
        for (auto &e : times) {
            adjs[e[0] - 1].push_back({e[1] - 1, e[2]});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k - 1});
        dist[k - 1] = 0;
        int remain = n;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            if (--remain == 0) {
                return d;
            }
            for (auto &[v, w] : adjs[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};
