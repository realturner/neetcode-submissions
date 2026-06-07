// 15:30
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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        auto go = [&](this auto &&go, TreeNode *node, int pathMax) -> void {
            if (node) {
                pathMax = max(pathMax, node->val);
                if (pathMax == node->val) {
                    ans++;
                }
                go(node->left, pathMax);
                go(node->right, pathMax);
            }
        };
        go(root, INT_MIN);
        return ans;
    }
};
