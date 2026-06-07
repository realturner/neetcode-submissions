// 15:24
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        auto go = [&](this auto &&go, TreeNode* u, int depth) -> void {
            if (u) {
                if (depth == ans.size()) {
                    ans.push_back(u->val);
                } else {
                    ans[depth] = u->val;
                }
                go(u->left, depth + 1);
                go(u->right, depth + 1);
            }
        };
        go(root, 0);
        return ans;
    }
};
