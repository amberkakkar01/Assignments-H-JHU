/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>

using namespace std;

int dfs(TreeNode<int> *root, int &ans) {
    if (root == NULL)
        return 0;
    int left = dfs(root->left, ans);
    int right = dfs(root->right, ans);
    int sum = left + right + root->data;
    ans = max(ans, sum);
    return sum;
}

int largestSubtreeSum(TreeNode<int> *root) {
    // Write your code here.
    int ans = INT_MIN;
    dfs(root, ans);
    return ans;
}