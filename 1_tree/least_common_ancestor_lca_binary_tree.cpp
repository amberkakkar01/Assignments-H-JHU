
// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

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

class Solution
{
public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lcaAnotherOptimal(Node* root , int n1 , int n2 )
    {
        //Your code here
        if (root == NULL or root->data == n1 or root->data == n2)
        {
            return root;
        }
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
            return root;
    }
    bool path(Node* root, vector<Node*>&p, int k)
    {
        if (root == NULL)
            return false;
        p.push_back(root);
        if (root->data == k)
            return true;
        if (path(root->left, p, k) || path(root->right, p, k))
            return true;
        p.pop_back();
        return false;
    }
    Node* lcaBrute(Node* root , int n1 , int n2 )
    {
        //Your code here
        vector<Node*> p1;
        vector<Node*> p2;
        if (!path(root, p1, n1) || !path(root, p2, n2))
            return NULL;
        int i = 0;
        for (i = 0; i < p1.size() && i < p2.size(); i++)
        {
            if (p1[i] != p2[i])
                break;
        }
        return p1[i - 1];
    }
};

Node* lcaOptimal(Node* root , int n1 , int n2 )
{
    //Your code here
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    if (left and right)
        return root;

    return (left != NULL) ? left : right;
}
};

// { Driver Code Starts.

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d ", &a, &b);
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.lca(root, a, b)->data << endl;
    }
    return 0;
}
// } Driver Code Ends