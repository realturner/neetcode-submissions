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
        const int n = word.length();
        auto go = [&](this auto &&go, TrieNode *u, int i) {
            while (u && i < n && word[i] != '.') {
                u = u->nexts[word[i++] - 'a'];
            }
            if (u == nullptr) {
                return false;
            } else if (i == n) {
                return u && u->isEnd;
            }
            for (auto v : u->nexts) {
                if (v && go(v, i + 1)) {
                    return true;
                }
            }
            return false;
        };
        return go(root, 0);
    }
};
