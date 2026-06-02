// 14:39
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
    bool isBalanced(TreeNode* root) {
        function<pair<int,bool>(TreeNode*)> go = [&](TreeNode *u) -> pair<int,bool> {
            if (u == nullptr) {
                return {0, true};
            }
            auto left = go(u->left), right = go(u->right);
            return {
                max(left.first, right.first) + 1,
                left.second && right.second && abs(left.first - right.first) <= 1
            };
        };
        return go(root).second;
    }
};
