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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int n = lists.size();
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode *sentinel = new ListNode(), *tail = sentinel;
        while (!pq.empty()) {
            auto [val, u] = pq.top();
            pq.pop();
            tail->next = u;
            tail = u;
            u = u->next;
            if (u) {
                pq.push({u->val, u});
            }
        }
        return sentinel->next;
    }
};
