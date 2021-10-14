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
    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void fillList(TreeNode* root, int level, int low, int high, vector<vector<string>> &res)
    {
        if (root == NULL)
        {
            return;
        }
        int mid = (low + high) / 2;
        res[level][mid] = to_string(root->val);
        fillList(root->left, level + 1, low, mid - 1, res);
        fillList(root->right, level + 1, mid + 1, high, res);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int row = height(root);
        int col = pow(2, row) - 1;
        vector<vector<string>> res(row, vector<string>(col, ""));
        fillList(root, 0, 0, col, res);
        return res;

    }
};