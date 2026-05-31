// 15:49
class TrieNode {
public:
    TrieNode *nexts[26];
    int refs = 0;
    int idx = -1;
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
        const int w = words.size();
        TrieNode *root = new TrieNode();
        for (int i = 0; i < w; i++) {
            auto &word = words[i];
            auto node = root;
            node->refs++;
            for (char ch : word) {
                auto &next = node->nexts[ch - 'a'];
                if (next == nullptr) {
                    next = new TrieNode();
                }
                node = next;
                node->refs++;
            }
            node->idx = i;
        }
        vector<TrieNode*> curr = {root};
        vector<string> ans;
        function<void(int,int,TrieNode*)> go = [&](int i, int j, TrieNode *u) {
            if (u == nullptr || u->refs == 0) {
                return;
            } else if (u->idx != -1) {
                ans.push_back(words[u->idx]);
                u->idx = -1;
                for (auto p : curr) {
                    p->refs--;
                }
            }
            for (int di = 1, dj = 0, r = 0; r < 4; r++) {
                swap(di, dj);
                di = -di;
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || board[ii][jj] == '!') {
                    continue;
                }
                char ch = board[ii][jj];
                auto v = u->nexts[ch - 'a'];
                if (v) {
                    board[ii][jj] = '!';
                    curr.push_back(v);
                    go(ii, jj, v);
                    curr.pop_back();
                    board[ii][jj] = ch;
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto ch = board[i][j];
                if (root->nexts[ch - 'a']) {
                    board[i][j] = '!';
                    curr.push_back(root->nexts[ch - 'a']);
                    go(i, j, root->nexts[ch - 'a']);
                    curr.pop_back();
                    board[i][j] = ch;
                }
            }
        }
        deleteNodes(root);
        return ans;
    }
};
