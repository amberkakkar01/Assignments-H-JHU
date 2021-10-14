//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

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
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	void preorder(Node* root, vector<Node*>& r)
	{
		if (root == NULL)
			return ;
		r.push_back(root);
		preorder(root->left, r);
		preorder(root->right, r);
	}

	void flatten(Node *root)
	{
		//code here
		vector<Node*> r;
		if (root == NULL)
			return;
		preorder(root, r);
		for (int i = 0; i < r.size() - 1; i++)
		{
			Node* t = r[i];
			t->left = NULL;
			t->right = r[i + 1];
		}

	}
};

// { Driver Code Starts.
int main() {

	int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);

		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	}

	return 0;
}
// } Driver Code Ends

class Solution {
public:
	void flatten(TreeNode *root) {

		if (!root) return;

		TreeNode* node = root;
		while (node) {

			// Attatches the right sub-tree to the rightmost leaf of the left sub-tree:
			if (node->left) {

				TreeNode *rightMost = node->left;
				while (rightMost->right) {

					rightMost = rightMost->right;
				}
				rightMost->right = node->right;

				// Makes the left sub-tree to the right sub-tree:
				node->right = node->left;
				node->left = NULL;
			}

			// Flatten the rest of the tree:
			node = node->right;
		}
	}
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A)
{
	if (A == NULL)
		return NULL;
	TreeNode *node = A;
	while (node != NULL)
	{
		if (node->left != NULL)
		{
			TreeNode *rtmost = node->left;
			while (rtmost->right != NULL)
				rtmost = rtmost->right;
			rtmost->right = node->right;
			node->right = node->left;
			node->left = NULL;
		}
		node = node->right;
	}
	return A;
}

