// 11:46
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto go = [&](this auto &&go, TreeNode *u) -> int {
            int l = u->left == nullptr ? 0 : go(u->left) + 1;
            int r = u->right == nullptr ? 0 : go(u->right) + 1;
            ans = max(ans, l + r);
            return max(l, r);
        };
        go(root);
        return ans;
    }
};
