// 15:49
class TrieNode {
public:
    TrieNode *nexts[26];
    bool isEnd = false;
};
class Solution {
    void deleteNodes(TrieNode *u) {
        if (u) {
            for (auto v : u->nexts) {
                deleteNodes(v);
            }
            delete u;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int m = board.size(), n = board[0].size();
        TrieNode *root = new TrieNode();
        for (auto &word : words) {
            auto node = root;
            for (char ch : word) {
                auto &next = node->nexts[ch - 'a'];
                if (next == nullptr) {
                    next = new TrieNode();
                }
                node = next;
            }
            node->isEnd = true;
        }
        string curr;
        vector visited(m, vector<bool>(n, false));
        vector<string> ans;
        function<void(int,int,TrieNode*)> go = [&](int i, int j, TrieNode *u) {
            if (u == nullptr) {
                return;
            } else if (u->isEnd) {
                u->isEnd = false;
                ans.push_back(curr);
            }
            for (int di = 1, dj = 0, r = 0; r < 4; r++) {
                swap(di, dj);
                di = -di;
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii][jj]) {
                    continue;
                }
                auto v = u->nexts[board[ii][jj] - 'a'];
                if (v) {
                    visited[ii][jj] = true;
                    curr.push_back(board[ii][jj]);
                    go(ii, jj, v);
                    curr.pop_back();
                    visited[ii][jj] = false;
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto ch = board[i][j];
                if (root->nexts[ch - 'a']) {
                    visited[i][j] = true;
                    curr.push_back(ch);
                    go(i, j, root->nexts[ch - 'a']);
                    curr.pop_back();
                    visited[i][j] = false;
                }
            }
        }
        deleteNodes(root);
        return ans;
    }
};
