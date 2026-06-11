// 09:48
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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        auto go = [&](this auto &&go, TreeNode *u) -> bool {
            if (u == nullptr) {
                return false;
            }
            if (go(u->left)) {
                return true;
            }
            if (--k == 0) {
                ans = u->val;
                return true;
            }
            return go(u->right);
        };
        go(root);
        return ans;
    }
};
