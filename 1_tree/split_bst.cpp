#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

Node* buildTree(int n) {

	int d;
	cin >> d;
	Node* root = new Node(d);
	queue<Node*> q;
	q.push(root);
	int i = 1;
	while (!q.empty() and i < n)
	{
		Node* curr = q.front();
		q.pop();
		cin >> d;
		if (d == -1)
			curr->left = NULL;
		else
		{
			curr->left = new Node(d);
			q.push(curr->left);
		}
		cin >> d;
		if (d == -1)
			curr->right = NULL;
		else
		{
			curr->right = new Node(d);
			q.push(curr->right);
		}
		i += 2;
	}
	return root;
}


void inorder(Node* root, vector<int>&main)
{
	if (!root)
		return;
	inorder(root->left, main);
	main.push_back(root->val);
	inorder(root->right, main);
}

Node* ArraytoBST(vector<int> r, int low, int high)
{
	if (low > high)
		return NULL;
	int mid = (low + high) / 2;
	Node* root = new Node(r[mid]);
	root->left = ArraytoBST(r, low, mid - 1);
	root->right = ArraytoBST(r, mid + 1, high);
	return root;
}
vector<Node*> splitBST (Node* root, int value)
{
	// Write your code here.
	vector<int> main;
	inorder(root, main);
	vector<int> first, second;
	for (int i = 0; i < main.size(); i++)
	{
		cout << main[i] << " ";
		if (main[i] <= value)
			first.push_back(main[i]);
		else if (main[i] > value)
			second.push_back(main[i]);
	}
	cout << endl;
	// sort(first.begin(), first.end());
	// sort(second.begin(), second.end());
	Node* root1 = ArraytoBST(first, 0, first.size() - 1);
	Node* root2 = ArraytoBST(second, 0, second.size() - 1);
	vector<Node*> res;
	res.push_back(root1);
	res.push_back(root2);
	return res;
}

void inorderTraversal(Node* root)
{
	if (!root)
		return;
	inorderTraversal(root->left);
	cout << root->val << " ";
	inorderTraversal(root->right);
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Node* root = buildTree(n);
		int  value;
		cin >> value;
		vector<Node*> r = splitBST(root, value);
		cout << r[0]->val << endl;
		inorderTraversal(r[0]);
		cout << endl;
		cout << r[1]->val << endl;
		inorderTraversal(r[1]);
		cout << endl;
	}


	return 0;
}

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the total number of nodes in the given tree.
*/

// Recursive function to split the given tree into two trees.
vector<TreeNode<int>* > splitBST(TreeNode<int>* root, int value)
{
	// Initialize vector of size two with 'NULL' nodes of 'first' and 'second' trees.
	vector<TreeNode<int>* > ret(2, NULL);

	// Base case
	if (root == NULL)
	{
		return ret;
	}

	/*
	 If the value of root node is less than or equal to given value,
	 then add left subtree along with root node to the 'first' tree.
	 and recursively call function for right subtree. And if value of
	 root node is greator than given value, then add right subtree along with
	 root node to 'second' tree ans recursively call function for left subtree.
	*/
	if (root -> val <= value)
	{
		ret[0] = root;
		vector<TreeNode<int>* > temp = splitBST(root -> right, value);
		root -> right = temp[0];
		ret[1] = temp[1];
	}
	else
	{
		ret[1] = root;
		vector<TreeNode<int>* > temp = splitBST(root -> left, value);
		root -> left = temp[1];
		ret[0] = temp[0];
	}

	// Return vector of root nodes of 'first' and 'second' trees.
	return ret;
}

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where N is the total number of nodes in the given tree.
*/

vector<TreeNode<int>* > splitBST (TreeNode<int>* root, int value)
{
	// Initialize vector of size two with node of 'first' and 'second' trees.
	vector<TreeNode<int>* > afterSplit(2, new TreeNode<int>(0));

	// Declare a current node variables for the first and second trees to keep track for adding next node.
	TreeNode<int>* currFirst = afterSplit[0];
	TreeNode<int>* currSecond = afterSplit[1];

	// Run a loop until we process whole tree.
	while (root != NULL)
	{
		/*
		If value of current root is less than or equal to given value,
		then add a new node with value equal to root's value to the right child of 'currFirst',
		as we are assuming that left subtree is already been added. Then move 'currFirst' to
		its right child and add left subtree of root node.
		*/
		if (root -> val <= value)
		{
			currFirst -> right = new TreeNode<int>(root -> val);
			currFirst = currFirst -> right;
			currFirst -> left  = root ->left;

			// Move root node to its right child to explore right subtree.
			root = root -> right;
		}

		/*
		If value of current root is greater than given value,
		then add a new node with value equal to root's value to the left child of 'currSecond',
		as we are assuming that right subtree is already been added. Then move 'currSecond' to
		its left child and add right subtree of root node.
		*/
		else
		{
			currSecond -> left = new TreeNode<int> (root -> val);
			currSecond = currSecond -> left;
			currSecond -> right = root -> right;

			// Move root node to left subtree.
			root  = root -> left;
		}
	}

	/*
	 The root node of 'first' and 'second' trees are added as right child and left child
	 of 'afterSplit[0]' and 'afterSplit[1]' respectively. So we will return
	 'afterSplit[0] -> right' and 'afterSplit[1] -> left'.
	*/
	afterSplit[0] = afterSplit[0] -> right;
	afterSplit[1] = afterSplit[1] -> left;

	return afterSplit;
}