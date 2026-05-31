// 19:00
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
    void reorderList(ListNode* head) {
        ListNode *mid, *tail;
        for (mid = tail = head; tail && tail->next; ) {
            tail = tail->next->next;
            mid = mid->next;
        }
        // say the length of linked list is n
        // tail is positioned at n - 1 if odd, n if even
        // mid is positioned at floor(n/2)
        // for odd length the final look should be like:
        //   ......, mid
        // for even length should be:
        //   ......, mid - 1, mid
        // so:
        // firstly reverse the list from mid to tail
        tail = mid;
        for (ListNode *p = mid, *q = mid->next, *r; q != nullptr; ) {
            r = q->next;
            q->next = p;
            tail = p = q;
            q = r;
        }
        for (ListNode *p = head, *q = tail, *tmp; p != q && p->next != q; ) {
            // insert q between p and p->next
            tmp = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = tmp;
        }
        mid->next = nullptr;
    }
};
