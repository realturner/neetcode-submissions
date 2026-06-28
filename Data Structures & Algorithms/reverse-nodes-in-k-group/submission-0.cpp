// 09:12
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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *sentinel = new ListNode(-1, head);
        ListNode *p = sentinel, *q = sentinel;
        while (q) {
            for (int i = 0; q && i < k; i++) {
                q = q->next;
            }
            if (q == nullptr) {
                break;
            }
            ListNode *tmp = q->next, *r = p->next;
            p->next = q;
            for (ListNode *u = r, *v = r->next; u != q;) {
                tmp = v->next;
                v->next = u;
                u = v;
                v = tmp;
            }
            r->next = tmp;
            p = q = r;
        }
        return sentinel->next;
    }
};
