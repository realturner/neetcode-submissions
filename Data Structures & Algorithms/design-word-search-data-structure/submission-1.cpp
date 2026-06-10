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
            if (i == n) {
                return u->isEnd;
            }
            if (word[i] == '.') {
                for (auto v : u->nexts) {
                    if (v && go(v, i + 1)) {
                        return true;
                    }
                }
            } else if (u->nexts[word[i] - 'a']) {
                return go(u->nexts[word[i] - 'a'], i + 1);
            }
            return false;
        };
        return go(root, 0);
    }
};
