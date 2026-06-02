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
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << "data: " << data << endl;
        const int length = data.size();
        int i = 0;
        function<TreeNode*()> go = [&]() -> TreeNode* {
            if (i == length) {
                return nullptr;
            } else if (data[i] == ',') {
                ++i;
                return nullptr;
            }
            int val = 0, sign = 1;
            if (data[i] == '-') {
                sign = -1;
                i++;
            }
            while (data[i] != ',') {
                val = val * 10 + data[i] - '0';
                i++;
            }
            TreeNode* ans = new TreeNode(sign * val);
            i++;
            ans->left = go();
            ans->right = go();
            return ans;
        };
        return go();
    }
};
