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
            if (u == nullptr) {
                return 0;
            }
            auto l = go(u->left), r = go(u->right);
            ans = max(ans, l + r);
            return max(l, r) + 1;
        };
        go(root);
        return ans;
    }
};
