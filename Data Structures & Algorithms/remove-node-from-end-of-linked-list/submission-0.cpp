// 09:00
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *sentinel = new ListNode(-1, head);
        ListNode *p, *q = head;
        for (int i = 0; q && i < n; i++) {
            q = q->next;
        }
        for (p = sentinel; q != nullptr; q = q->next) {
            p = p->next;
        }
        p->next = p->next->next;
        return sentinel->next;
    }
};
