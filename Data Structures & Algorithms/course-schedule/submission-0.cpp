// 11:10
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> depCounts(numCourses, 0);
        vector<vector<int>> adjs(numCourses);
        for (auto &e : prerequisites) {
            adjs[e[0]].push_back(e[1]);
            depCounts[e[1]]++;
        }
        queue<int> q;
        int remain = numCourses;
        for (int i = 0; i < numCourses; i++) {
            if (depCounts[i] == 0) {
                remain--;
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (int v : adjs[u]) {
                if (--depCounts[v] == 0) {
                    remain--;
                    q.push(v);
                }
            }
        }
        return remain == 0;
    }
};
