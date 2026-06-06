// 20:04
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        const int n = words.size();
        vector<unordered_set<int>> adj(26);
        vector<bool> vis(26, false);
        vector<int> depCount(26, 0);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (j == words[i + 1].length()) {
                    return "";
                }
                if (words[i][j] != words[i + 1][j]) {
                    int u = words[i][j] - 'a', v = words[i + 1][j] - 'a';
                    if (adj[u].count(v) == 0) {
                        adj[u].insert(v);
                        depCount[v]++;
                    }
                    break;
                }
            }
        }
        for (auto &w : words) {
            for (char ch : w) {
                vis[ch - 'a'] = true;
            }
        }
        string ans = "";
        int unresolved = 0;
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (vis[i]) {
                if (depCount[i] == 0) {
                    ans += i + 'a';
                    q.push(i);
                } else {
                    unresolved++;
                }
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (--depCount[v] == 0) {
                    q.push(v);
                    --unresolved;
                    ans += v + 'a';
                }
            }
        }
        return unresolved == 0 ? ans : "";
    }
};
