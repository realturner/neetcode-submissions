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
        const int n = preorder.size();
        using It = vector<int>::iterator;
        auto go = [&](this auto &&go, It pl, It pr, It il, It ir) -> TreeNode* {
            if (pl == pr) {
                return nullptr;
            }
            auto im = il, pm = pl + 1;
            while (*im != *pl) {
                ++im;
                ++pm;
            }
            return new TreeNode(
                *pl,
                go(pl + 1, pm, il, im),
                go(pm, pr, im + 1, ir)
            );
        };
        return go(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
