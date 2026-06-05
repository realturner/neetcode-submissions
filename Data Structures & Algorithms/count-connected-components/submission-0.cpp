class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
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
        int ans = n;
        for (auto &e : edges) {
            int x = find(e[0]), y = find(e[1]);
            if (x != y) {
                ans--;
                roots[x] = y;
            }
        }
        return ans;
    }
};
