// 10:36
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
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
        for (auto &e : edges) {
            auto x = find(e[0]), y = find(e[1]);
            if (x == y) {
                return false;
            }
            roots[x] = y;
        }
        return true;
    }
};
