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
            auto pivot = il;
            while (pivot != ir && *pivot != *pl) {
                ++pivot;
            }
            int leftSize = distance(il, pivot);
            return new TreeNode(
                *pl,
                go(pl + 1, pl + 1 + leftSize, il, pivot),
                go(pl + 1 + leftSize, pr, pivot + 1, ir)
            );
        };
        return go(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
