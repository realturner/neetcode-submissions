// 00:14
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> cloneMap;
        unordered_set<Node*> cloned;
        function<Node*(Node*)> go = [&](Node *u) -> Node* {
            if (u == nullptr) {
                return nullptr;
            }
            auto &x = cloneMap[u];
            if (cloned.count(u)) {
                return x;
            }
            if (x == nullptr) {
                x = new Node(u->val);
                for (auto v : u->neighbors) {
                    x->neighbors.push_back(go(v));
                }
                cloned.insert(u);
            }
            return x;
        };
        return go(node);
    }
};
