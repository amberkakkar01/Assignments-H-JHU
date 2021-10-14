#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

node* levelOrderbuild()
{
	int d;
	cin >> d;
	node* root = new node(d);
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* current = q.front();
		q.pop();
		int c1, c2;
		cin >> c1 >> c2;
		if (c1 != -1)
		{
			current->left = new node(c1);
			q.push(current->left);
		}
		if (c2 != -1)
		{
			current->right = new node(c2);
			q.push(current->right);
		}
	}
	return root;
}

void levelOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
				q.push(NULL);
		}
		else
		{
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}

void leftView(node* root, int level, map<int, int> &m)
{
	if (root == NULL)
		return;
	if (m.find(level) == m.end())
		m[level] = root->data;
	leftView(root->left, level + 1, m);
	leftView(root->right, level + 1, m);
}

void preorder(Node* root, int level, int &maxlevel, vector<int> &res)
{
	if (!root)
		return;
	if (maxlevel < level)
	{
		res.push_back(root->data);
		maxlevel = level;
	}
	preorder(root->left, level + 1, maxlevel, res);
	preorder(root->right, level + 1, maxlevel, res);
}
vector<int> leftViewRecur(Node *root)
{
	// Your code here
	vector<int> res;
	int maxlevel = 0;
	preorder(root, 1, maxlevel, res);
	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	node* root = levelOrderbuild();
	levelOrder(root);
	map<int, int> m;
	leftView(root, 0, m);
	for (auto i : m)
		cout << i.second << " ";
	cout << endl;


	return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


// Function to Build Tree
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

	// for(string i:ip)
	//     cout<<i<<" ";
	// cout<<endl;
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


int main() {
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin, s);
		Node* root = buildTree(s);
		vector<int> vec = leftView(root);
		for (int x : vec)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
	// Your code here
	vector<int> res;
	if (!root)
		return res;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 1; i <= size; i++)
		{
			Node* curr = q.front();
			q.pop();
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
			if (i == 1)
				res.push_back(curr->data);
		}
	}
	return res;
}
