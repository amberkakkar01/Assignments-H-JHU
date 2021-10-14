#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	int key;
	Node* left;
	Node* right;
	Node(int x)
	{
		this->key = x;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insert(Node * root, int key) {
	if (root == NULL) {
		return new Node(key);
	}

	//rec case
	if (key < root->key) {
		root->left = insert(root->left, key);
	}
	else {
		root->right = insert(root->right, key);
	}
	return root;

}

void inorder(Node *root) {
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

Node* LCA(Node *root, int n1, int n2)
{
	if (root == NULL)
		return NULL;
	if (root->key > n1 and root->key > n2)
		return LCA(root->left, n1, n2);
	else if (root->key < n1 and root->key < n2)
		return LCA(root->right, n1, n2);
	return root;
}

int maxOfPath(Node *root, int n1)
{
	if (root == NULL)
		return 0;
	int left = 0, right = 0;
	if (root->key > n1)
		left = maxOfPath(root->left, n1);
	if (root->key < n1)
		right = maxOfPath(root->right, n1);
	return max(root->key, max(left, right));
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
		int n, x, a, b;
		cin >> n >> a >> b;
		Node* root = NULL;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			root = insert(root, x);
		}

		inorder(root);
		cout << '\n';

		Node* lca = LCA(root, a, b);
		cout << max(maxOfPath(lca, a), maxOfPath(lca, b)) << '\n';

	}



	return 0;
}