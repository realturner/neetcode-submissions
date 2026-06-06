// 18:32
class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        const int n = wordList.size(), m = beginWord.length();
        unordered_map<string,vector<int>> masked;
        auto buildMasked = [&](string &s, int i) -> void {
            char tmp;
            for (int j = 0; j < m; j++) {
                tmp = s[j];
                s[j] = '?';
                masked[s].push_back(i);
                s[j] = tmp;
            }
        };
        buildMasked(beginWord, -1);
        int endIndex = -1;
        for (int i = 0; i < n; i++) {
            buildMasked(wordList[i], i);
            if (wordList[i] == endWord) {
                endIndex = i;
            }
        }
        if (endIndex == -1) {
            return 0;
        }
        auto getIndices = [&](string &w) -> vector<int> {
            char tmp;
            vector<int> ans;
            for (int i = 0; i < m; i++) {
                tmp = w[i];
                w[i] = '?';
                for (int j : masked[w]) {
                    if (j != -1) {
                        ans.push_back(j);
                    }
                }
                w[i] = tmp;
            }
            return ans;
        };
        queue<int> q;
        vector<bool> seen(n, false);
        for (int u : getIndices(beginWord)) {
            q.push(u);
            seen[u] = true;
        }
        for (int step = 2; !q.empty(); step++) {
            for (int k = q.size(); k > 0; k--) {
                int u = q.front();
                if (u == endIndex) {
                    return step;
                }
                q.pop();
                for (int v : getIndices(wordList[u])) {
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
