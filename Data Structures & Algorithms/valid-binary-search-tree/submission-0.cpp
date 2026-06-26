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
        auto go = [&](this auto &&go, TreeNode *u) -> tuple<bool,int,int> {
            int l = u->val, r = u->val;
            if (u->left) {
                auto [sub, ll, lr] = go(u->left);
                if (!sub || lr >= u->val) {
                    return {false, INT_MIN, INT_MAX};
                }
                l = ll;
            }
            if (u->right) {
                auto [sub, rl, rr] = go(u->right);
                if (!sub || rl <= u->val) {
                    return {false, INT_MIN, INT_MAX};
                }
                r = rr;
            }
            return {true, l, r};
        };
        return get<0>(go(root));
    }
};
