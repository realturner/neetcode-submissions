// 08:30
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        const int n = numCourses;
        vector<int> depCounts(n);
        vector<vector<int>> adjs(n);
        for (auto &e : prerequisites) {
            depCounts[e[0]]++;
            adjs[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (depCounts[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        int remain = n;
        while (!q.empty()) {
            int u = q.front();
            remain--;
            ans.push_back(u);
            q.pop();
            for (int v : adjs[u]) {
                if (--depCounts[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (remain > 0) {
            ans.clear();
        }
        return ans;
    }
};
