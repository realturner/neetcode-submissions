// 18:32
class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        const int n = wordList.size(), m = beginWord.length();
        unordered_map<string,vector<int>> masked;
        wordList.push_back(beginWord);
        int endIndex = -1;
        for (int i = 0; i <= n; i++) {
            if (i < n && wordList[i] == endWord) {
                endIndex = i;
            }
            char tmp;
            auto &w = wordList[i];
            for (int j = 0; j < m; j++) {
                tmp = w[j];
                w[j] = '?';
                masked[w].push_back(i);
                w[j] = tmp;
            }
        }
        if (endIndex == -1) {
            return 0;
        }
        queue<int> q;
        vector<bool> seen(n + 1, false);
        q.push(n);
        seen[n] = true;
        for (int step = 1; !q.empty(); step++) {
            for (int k = q.size(); k > 0; k--) {
                int u = q.front();
                if (u == endIndex) {
                    return step;
                }
                q.pop();
                auto &w = wordList[u];
                for (int j = 0; j < m; j++) {
                    char tmp = w[j];
                    w[j] = '?';
                    for (int v : masked[w]) {
                        if (!seen[v]) {
                            seen[v] = true;
                            q.push(v);
                        }
                    }
                    w[j] = tmp;
                }
            }
        }
        return 0;
    }
};
