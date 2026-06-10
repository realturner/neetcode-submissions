// 16:46
class TrieNode {
public:
    TrieNode *nexts[26];
    bool isEnd = false;
};
class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto u = root;
        for (char ch : word) {
            auto &next = u->nexts[ch - 'a'];
            if (!next) {
                next = new TrieNode();
            }
            u = next;
        }
        u->isEnd = true;
    }
    
    bool search(string word) {
        queue<TrieNode*> q;
        q.push(root);
        for (char ch : word) {
            for (int k = q.size(); k > 0; k--) {
                auto u = q.front();
                q.pop();
                if (ch == '.') {
                    for (auto v : u->nexts) {
                        if (v) {
                            q.push(v);
                        }
                    }
                } else if (u->nexts[ch - 'a']) {
                    q.push(u->nexts[ch - 'a']);
                }
            }
        }
        while (!q.empty()) {
            if (q.front()->isEnd) {
                return true;
            }
            q.pop();
        }
        return false;
    }
};
