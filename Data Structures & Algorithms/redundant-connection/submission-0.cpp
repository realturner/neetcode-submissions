// 21:47
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < n; i++) {
            auto &e = edges[i];
            adj[e[0] - 1].push_back({e[1] - 1, i});
            adj[e[1] - 1].push_back({e[0] - 1, i});
        }
        vector<bool> visited(n, false);
        vector<pair<int,int>> curr; // (node, edgeIndex)
        int index = -1;
        function<void(int,int)> go = [&](int u, int p) {
            // cerr << u << ' ' << p << endl;
            if (visited[u]) {
                if (index == -1) {
                    // cout << "loop: ";
                    // for (auto [u, idx] : curr) {
                    //     cout << "(" << u << ", " << idx << ") ";
                    // }
                    // cout << endl;
                    index = curr.back().second;
                    for (int j = curr.size() - 2; j >= 0 && curr[j].first != u; j--) {
                        index = max(index, curr[j].second);
                    }
                }
                return;
            }
            visited[u] = true;
            for (auto &[v, idx] : adj[u]) {
                if (v != p) {
                    curr.push_back({v, idx});
                    go(v, u);
                    curr.pop_back();
                }
            }
        };
        curr.push_back({0, -1});
        go(0, -1);

        return edges[index];
    }
};
