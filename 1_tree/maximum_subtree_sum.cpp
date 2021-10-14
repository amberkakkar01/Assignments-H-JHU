/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>

using namespace std;

long long dfs(BinaryTreeNode<int> *root, long long &ans) {
    if (root == NULL)
        return 0;
    long long left = dfs(root->left, ans);
    long long right =  dfs(root->right, ans);
    long long sum = left + right + root->data;
    ans = max(ans, sum);
    return sum;
}

long long maxSubtreeSum(BinaryTreeNode<int> *root) {
    // Write your code here.
    long long ans = LLONG_MIN;
    dfs(root, ans);
    return ans;
}
