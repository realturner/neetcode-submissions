// 10:25
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
    bool isValidBST(TreeNode* root) {
        auto go = [&](this auto &&go, TreeNode *u, int l, int r) -> bool {
            return u->val >= l && u->val <= r
                && (u->left == nullptr || go(u->left, l, u->val - 1))
                && (u->right == nullptr || go(u->right, u->val + 1, r));
        };
        return go(root, INT_MIN, INT_MAX);
    }
};
