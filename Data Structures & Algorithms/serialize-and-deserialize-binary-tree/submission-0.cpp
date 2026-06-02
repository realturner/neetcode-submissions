// 11:42
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        return to_string(root->val) + "(" + serialize(root->left) + ")(" + serialize(root->right) + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        function<TreeNode*(int,int)> go = [&](int i, int j) -> TreeNode* {
            if (i == j) {
                return nullptr;
            }
            int l, r, depth;
            for (l = i; data[l] != '('; l++);
            for (depth = 1, r = l + 1; depth > 0; r++) {
                if (data[r] == '(') {
                    depth++;
                } else if (data[r] == ')') {
                    depth--;
                }
            }
            return new TreeNode(
                stoi(data.substr(i, l - i)),
                go(l + 1, r - 1),
                go(r + 1, j - 1)
            );
        };
        return go(0, data.length());
    }
};
