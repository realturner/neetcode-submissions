// 18:32
class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        const int n = wordList.size(), w = beginWord.length();
        int endIndex = -1;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                endIndex = i;
            }
            for (int j = i + 1; j < n; j++) {
                int diffCount = 0;
                for (int k = 0; k < w && diffCount < 2; k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        diffCount++;
                    }
                }
                if (diffCount == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if (endIndex == -1) {
            return 0;
        }
        queue<int> q;
        vector<bool> seen(n, false);
        q.push(n - 1);
        seen[n - 1] = true;
        for (int step = 1; !q.empty(); step++) {
            for (int k = q.size(); k > 0; k--) {
                int u = q.front();
                if (u == endIndex) {
                    return step;
                }
                q.pop();
                for (int v : adj[u]) {
                    if (!seen[v]) {
                        seen[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return 0;
    }
};
