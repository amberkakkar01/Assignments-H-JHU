//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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


// } Driver Code Ends
//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        stack<Node*> s;
        Node* current = root;
        vector<int> res;
        /*   1
           /    \
          2      3
        /   \
        4     5

        Step 1 Creates an empty stack: S = NULL

        Step 2 sets current as address of root: current -> 1

        Step 3 Pushes the current node and set current = current->left
        until current is NULL
        current -> 1
        push 1: Stack S -> 1
        current -> 2
        push 2: Stack S -> 2, 1
        current -> 4
        push 4: Stack S -> 4, 2, 1
        current = NULL

        Step 4 pops from S
        a) Pop 4: Stack S -> 2, 1
        b) print "4"
        c) current = NULL /*right of 4 */ //and go to step 3
        /* Since current is NULL step 3 doesn't do anything.

         Step 4 pops again.
         a) Pop 2: Stack S -> 1
         b) print "2"
         c) current -> 5/*right of 2 */ //and go to step 3

        /*Step 3 pushes 5 to stack and makes current NULL
        Stack S -> 5, 1
        current = NULL

        Step 4 pops from S
        a) Pop 5: Stack S -> 1
        b) print "5"
        c) current = NULL /*right of 5 */ //and go to step 3
        //Since current is NULL step 3 doesn't do anything*/*/

        /*  Step 4 pops again.
        a) Pop 1: Stack S -> NULL
          b) print "1"
          c) current -> 3 /*right of 1

          Step 3 pushes 3 to stack and makes current NULL
          Stack S -> 3
          current = NULL

                    Step 4 pops from S
        a) Pop 3: Stack S -> NULL
          b) print "3"
          c) current = NULL*/ /*right of 3 */

        //Traversal is done now as stack S is empty and current is NULL.* /
        // if current is NULL or stack is empty then we will come out of our
        // loop but if not then we will move in the left branch until it
        // becomes NULL and keeps pushing its data if current is NULL left
        // branch exhausted then we will move our current to right if the
        // stack  is not empty means many elements are waiting to get printed
        // so we will pick the top element that will be the parent node from
        // where current has come and set current as its right

        while (current or !s.empty())
        {
            while (current)
            {
                s.push(current);
                current = current->left;
            }
            if (!s.empty())
            {
                /*res.push_back(s.top()->data);
                current = s.top()->right;
                s.pop();*/
                current = s.top();
                res.push_back(current->data);
                current = current->right;
                s.pop();
            }
        }
        return res;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/



int main() {


    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);

        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.inOrder(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;

    }
    return 0;
}
// } Driver Code Ends