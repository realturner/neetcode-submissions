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
        using It = vector<int>::iterator;
        auto pi = preorder.begin(), ii = inorder.begin();
        auto go = [&](this auto &&go, TreeNode *u) -> TreeNode* {
            if (pi == preorder.end()) {
                return nullptr;
            } else if (u && u->val == *ii) {
                ++ii;
                return nullptr;
            }
            auto ans = new TreeNode(*(pi++));
            ans->left = go(ans);
            ans->right = go(u);
            return ans;
        };
        return go(nullptr);
    }
};
