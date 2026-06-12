// 12:12
class TrieNode {
public:
    TrieNode *nexts[26];
    bool isEnd = false;
};
class PrefixTree {
    TrieNode *root;
    TrieNode *traverse(string &word) {
        auto u = root;
        for (char ch : word) {
            if (u->nexts[ch - 'a'] == nullptr) {
                return nullptr;
            }
            u = u->nexts[ch - 'a'];
        }
        return u;
    }
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto u = root;
        for (auto ch : word) {
            auto &next = u->nexts[ch - 'a'];
            if (next == nullptr) {
                next = new TrieNode();
            }
            u = next;
        }
        u->isEnd = true;
    }
    
    bool search(string word) {
        auto u = traverse(word);
        return u && u->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto u = traverse(prefix);
        return u != nullptr;
    }
};
