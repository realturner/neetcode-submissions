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
            int j = i;
            auto u = root;
            do {
                u = u->nexts[s[j++] - 'a'];
                if (u && u->isEnd && !seen[j]) {
                    seen[j] = true;
                    q.push(j);
                }
            } while (j < n && u);
        }
        return false;
    }
};
