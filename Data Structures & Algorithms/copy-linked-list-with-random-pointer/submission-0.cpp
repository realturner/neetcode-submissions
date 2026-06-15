// 10:31
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (auto u = head; u; ) {
            auto v = new Node(u->val);
            v->next = u->next;
            u->next = v;
            u = v->next;
        }
        for (auto u = head; u; ) {
            u->next->random = u->random ? u->random->next : nullptr;
            u = u->next->next;
        }
        // cerr << "OK" << endl;
        Node *sentinel = new Node(INT_MIN), *tail = sentinel;
        for (auto u = head; u; ) {
            tail->next = u->next;
            tail = tail->next;
            // cerr << tail->val << ' ';
            u->next = tail->next;
            u = u->next;
        }
        // cerr << "end" << endl;
        return sentinel->next;
    }
};
