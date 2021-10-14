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
    unordered_map<int, int> m;
    int maxCount = 0;
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = left + right + root->val;
        maxCount = max(maxCount, ++m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto i : m)
        {
            if (i.second == maxCount)
                res.push_back(i.first);
        }
        return res;
    }
};