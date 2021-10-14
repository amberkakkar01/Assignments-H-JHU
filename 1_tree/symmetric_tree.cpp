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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        if (!root->left && !root->right)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty())
        {
            TreeNode* l = q.front();
            q.pop();
            TreeNode* r = q.front();
            q.pop();
            if (l->val != r->val)
                return false;
            if (l->left && r->right)
            {
                q.push(l->left);
                q.push(r->right);
            }
            else if (l->left || r->right)
                return false;
            if (l->right && r->left)
            {
                q.push(l->right);
                q.push(r->left);
            }
            else if (l->right || r->left)
                return false;
        }
        return true;

    }
};