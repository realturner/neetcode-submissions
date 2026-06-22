// 10:35
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
    string serialize(TreeNode *u) {
        if (u == nullptr) {
            return "()";
        }
        return "(" + to_string(u->val) + serialize(u->left) + serialize(u->right) + ")";
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        auto full = serialize(root), sub = serialize(subRoot);
        return full.find(sub) != string::npos;
    }
};
