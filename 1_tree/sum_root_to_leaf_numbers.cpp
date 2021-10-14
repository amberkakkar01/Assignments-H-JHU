class Solution {
public:
    int solve(TreeNode* root, int s)
    {
        if (!root)
            return 0;
        if (!root->left and !root->right)
            return s * 10 + root->val;
        return solve(root->left, s * 10 + root->val) + solve(root->right, s * 10 + (root->val));
    }
    int sumNumbers(TreeNode* root) {
        vector<int> r;
        return solve(root, 0);
    }
};