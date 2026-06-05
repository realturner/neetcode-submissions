// 11:01
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
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        auto go = [&](this auto &&go, TreeNode *u) -> int {
            if (u == nullptr) {
                return 0;
            }
            auto left = go(u->left), right = go(u->right);
            auto ret = u->val + max({0, left, right});
            ans = max({ans, ret, u->val + left + right});
            return ret;
        };
        go(root);
        return ans;
    }
};
