#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;

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

void connect(struct Node *p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */


void printSpecial(Node *root)
{
    if (root == NULL)
        return;

    Node* next_root = NULL;

    while (root != NULL)
    {
        cout << root->data << " ";

        if ( root->left && (!next_root) )
            next_root = root->left;
        else if ( root->right && (!next_root)  )
            next_root = root->right;

        root = root->nextRight;
    }

    printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// } Driver Code Ends
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
class Solution {

public:
    void connect(Node *root)
    {
        // Your Code Here
        queue<Node*> q;
        q.push(root);
        Node* temp = NULL;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node* prev = temp;
                temp = q.front();
                q.pop();
                if (i > 0)
                    prev->nextRight = temp;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            temp->nextRight = NULL;
        }
    }

};




// { Driver Code Starts.


/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution obj;
        obj.connect(root);
        printSpecial(root);
        cout << endl;
        inorder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the number of nodes in a binary tree.
*/

void connectNodes(BinaryTreeNode<int> *root) {

    // Keep the address of the first node of the current level.
    BinaryTreeNode<int> *startNode = root;

    while (startNode != NULL) {

        BinaryTreeNode<int> *ptr = startNode;
        BinaryTreeNode<int> *previous = NULL;
        startNode = NULL;

        // Traversing over nodes of current level and populating 'next' pointer of nodes of next level.
        while (ptr != NULL) {

            if (ptr->left != NULL) {

                if (previous != NULL) {
                    previous->next = ptr->left;
                }

                // Update 'startNode' with first node of next level if not already done.
                if (startNode == NULL) {
                    startNode = ptr->left;
                }

                // Update previous pointer
                previous = ptr->left;
            }

            if (ptr->right != NULL) {

                if (previous != NULL) {
                    previous->next = ptr->right;
                }

                // Update 'startNode' with first node of next level if not already done.
                if (startNode == NULL) {
                    startNode = ptr->right;
                }

                // Update previous pointer.
                previous = ptr->right;
            }

            ptr = ptr->next;
        }
    }
}

/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the number of nodes in a binary tree.
*/

#include <queue>

void connectNodes(BinaryTreeNode<int> *root) {

    // Create queue and enqueue address of root in it.
    queue< BinaryTreeNode<int>* > que;
    que.push(root);

    // Number of nodes in current level.
    int nodesCount = 1;

    while (!que.empty()) {
        BinaryTreeNode<int> *previous = NULL;

        // Traversing over nodes of current level.
        while (nodesCount > 0) {
            if (previous != NULL) {
                previous->next = que.front();
            }
            previous = que.front();

            // Pushing left and right child of current node in queue.
            if (que.front()->left != NULL) {
                que.push(que.front()->left);
            }
            if (que.front()->right != NULL) {
                que.push(que.front()->right);
            }
            que.pop();
            nodesCount--;
        }

        // Updating number of nodes in current level.
        nodesCount = que.size();
    }
}