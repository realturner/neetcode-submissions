// 15:34
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    using Iterator = vector<ListNode*>::iterator;
    ListNode *mergeAll(Iterator i, Iterator j) {
        int dist = distance(i, j);
        if (dist == 1) {
            return *i;
        }
        auto mid = i + dist / 2;
        auto a = mergeAll(i, mid), b = mergeAll(mid, j);
        ListNode *sentinel = new ListNode(), *tmp = sentinel;
        while (a || b) {
            if (b == nullptr || a != nullptr && a->val <= b->val) {
                tmp->next = a;
                tmp = a;
                a = a->next;
            } else {
                tmp->next = b;
                tmp = b;
                b = b->next;
            }
        }
        tmp = sentinel->next;
        delete sentinel;
        return tmp;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeAll(lists.begin(), lists.end());
    }
};
