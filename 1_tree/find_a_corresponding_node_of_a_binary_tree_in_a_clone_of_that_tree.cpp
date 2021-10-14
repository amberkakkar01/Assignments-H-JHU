/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorder(TreeNode* root, TreeNode* target, vector<TreeNode*> &ans)
    {
        if (!root)
            return;
        inorder(root->left, target, ans);
        if (root->val == target->val)
        {
            ans.push_back(root);
            return ;
        }
        inorder(root->right, target, ans);

    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<TreeNode*> ans;
        inorder(cloned, target, ans);
        return ans[0];
    }
};