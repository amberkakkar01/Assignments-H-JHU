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


/*I start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n. So if I pick i-th node as my root, the left subtree will contain elements 1 to (i-1), and the right subtree will contain elements (i+1) to n. I use recursive calls to get back all possible trees for left and right subtrees and combine them in all possible ways with the root.*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)   return vector<TreeNode*> ();
        return genTrees(1, n);
    }
    vector<TreeNode*> genTrees(int start, int end)
    {
        vector<TreeNode*> res;
        if (start > end)
        {
            res.push_back(NULL);
            return res;
        }
        else if (start == end)
        {
            res.push_back(new TreeNode(start));
            return res;
        }
        vector<TreeNode*>left, right;
        for (int i = start; i <= end; i++)
        {
            left = genTrees(start, i - 1);
            right = genTrees(i + 1, end);
            for (auto lnode : left)
            {
                for (auto rnode : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};