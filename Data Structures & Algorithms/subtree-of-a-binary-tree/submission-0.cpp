// 10:26
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        auto isSame = [&](this auto &&isSame, TreeNode *a, TreeNode *b) -> bool {
            if (a == nullptr || b == nullptr) {
                return a == nullptr && b == nullptr;
            }
            return a->val == b->val && isSame(a->left, b->left) && isSame(a->right, b->right);
        };
        auto go = [&](this auto &&go, TreeNode *u) -> bool {
            if (u == nullptr) {
                return subRoot == nullptr;
            }
            return isSame(u, subRoot) || go(u->left) || go(u->right);
        };
        return go(root);
    }
};
