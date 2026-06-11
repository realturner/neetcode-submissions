// 11:17
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto p = preorder.begin(), i = inorder.begin();
        auto go = [&](this auto &&go, TreeNode *tail) -> TreeNode* {
            if (p == preorder.end()) {
                return nullptr;
            } else if (tail && tail->val == *i) {
                ++i;
                return nullptr;
            }
            auto ans = new TreeNode(*(p++));
            ans->left = go(ans);
            ans->right = go(tail);
            return ans;
        };
        return go(nullptr);
    }
};
