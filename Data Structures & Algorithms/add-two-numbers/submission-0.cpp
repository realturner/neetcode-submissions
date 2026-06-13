// 16:48
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sentinel = new ListNode(), *tail = sentinel;
        int carry = 0;
        while (l1 && l2 || carry > 0) {
            carry = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            tail->next = new ListNode(carry % 10);
            carry /= 10;
            tail = tail->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        tail->next = l1 ? l1 : l2;
        return sentinel->next;
    }
};
