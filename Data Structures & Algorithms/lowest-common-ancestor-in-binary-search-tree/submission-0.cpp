// 15:59
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto u = root;
        while (u) {
            if (u->val < p->val && u->val < q->val) {
                u = u->right;
            } else if (u->val > p->val && u->val > q->val) {
                u = u->left;
            } else {
                break;
            }
        }
        return u;
    }
};
