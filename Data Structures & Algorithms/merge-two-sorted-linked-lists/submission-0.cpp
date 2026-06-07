// 14:28
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *sentinel = new ListNode(), *tail = sentinel;
        for (auto i = list1, j = list2; i || j; ) {
            if (j == nullptr || i != nullptr && i->val <= j->val) {
                tail->next = i;
                tail = i;
                i = i->next;
            } else {
                tail->next = j;
                tail = j;
                j = j->next;
            }
        }
        return sentinel->next;
    }
};
