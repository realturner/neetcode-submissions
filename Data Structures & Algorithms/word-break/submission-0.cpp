// 09:46
class TrieNode {
public:
    TrieNode *nexts[26];
    bool isEnd;
};
class Solution {
public:
    bool wordBreak(string &s, vector<string>& wordDict) {
        const int n = s.length();
        TrieNode *root = new TrieNode();
        for (auto &word : wordDict) {
            auto u = root;
            for (char ch : word) {
                auto &next = u->nexts[ch - 'a'];
                if (next == nullptr) {
                    next = new TrieNode();
                }
                u = next;
            }
            u->isEnd = true;
        }
        vector<vector<int>> skips(n);
        for (int i = 0; i < n; i++) {
            int len = 0;
            auto u = root;
            while (i + len < n && u) {
                if (u->isEnd) {
                    skips[i].push_back(len);
                }
                u = u->nexts[s[i + len] - 'a'];
                len++;
            }
            if (u && u->isEnd) {
                skips[i].push_back(len);
            }
        }
        queue<int> q;
        vector<bool> seen(n + 1, false);
        q.push(0);
        seen[0] = true;
        while (!q.empty()) {
            int i = q.front();
            if (i == n) {
                return true;
            }
            q.pop();
            for (int len : skips[i]) {
                if (!seen[i + len]) {
                    seen[i + len] = true;
                    q.push(i + len);
                }
            }
        }
        return false;
    }
};
