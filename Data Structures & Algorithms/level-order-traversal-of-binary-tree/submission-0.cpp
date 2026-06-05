// 09:37
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            vector<int> level;
            for (int k = q.size(); k > 0; k--) {
                auto u = q.front();
                q.pop();
                level.push_back(u->val);
                if (u->left) {
                    q.push(u->left);
                }
                if (u->right) {
                    q.push(u->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
