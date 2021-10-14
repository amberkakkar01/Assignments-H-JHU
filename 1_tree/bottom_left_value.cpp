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
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (i == 0)
                    ans = curr->val;
            }
        }
        return ans;
    }
};

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
    void preorder(TreeNode* root, int lvl, int &maxlevel, int &ans)
    {
        if (!root)
            return ;
        if (maxlevel < lvl)
        {
            ans = root->val;
            maxlevel = lvl;
        }
        preorder(root->left, lvl + 1, maxlevel, ans);
        preorder(root->right, lvl + 1, maxlevel, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0, maxlevel = 0;
        preorder(root, 1, maxlevel, ans);
        return ans;

    }
};