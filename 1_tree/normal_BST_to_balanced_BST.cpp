#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(struct Node* node, int key) {
    if (node == NULL) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node* node)
{
    if (node == NULL)return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node* node)
{
    if (node == NULL) return 0;
    else
    {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        if (lDepth > rDepth) return (lDepth + 1);
        else return (rDepth + 1);
    }
    return 2;
}
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout << height(root) << endl;
    }
    return 0;
}
// } Driver Code Ends


/*Structure of the Node of the BST is as
struct Node
{
    int data;
    Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST

void inorder(Node* root, vector<int> &r)
{
    if (!root)
        return;
    inorder(root->left, r);
    r.push_back(root->data);
    inorder(root->right, r);
}

Node* buildTree(vector<int> r, int low, int high)
{
    if (low > high)
        return NULL;
    int mid = (low + high) / 2;

    Node* root = new Node(r[mid]);
    root->left = buildTree(r, low, mid - 1);
    root->right = buildTree(r, mid + 1, high);
    return root;
}
Node* buildBalancedTree(Node* root)
{
    // Code here
    vector<int> r;
    inorder(root, r);

    return buildTree(r, 0, r.size() - 1);
}


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
    vector<TreeNode*> sortedArray;
    void inorder(TreeNode* root)
    {
        if (!root)
            return;
        inorder(root->left);
        sortedArray.push_back(root);
        inorder(root->right);
    }
    TreeNode* buildTree(int low, int high)
    {
        if (low > high)
            return NULL;
        int mid = (low + high) / 2;
        TreeNode* root = sortedArray[mid];
        root->left = buildTree(low, mid - 1);
        root->right = buildTree(mid + 1, high);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if (!root)
            return root;
        inorder(root);
        return buildTree(0, sortedArray.size() - 1);
    }
};