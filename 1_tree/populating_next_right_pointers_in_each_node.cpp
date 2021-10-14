/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* t = q.front();
            q.pop();
            if (t->left && t->right)
            {
                t->left->next = t->right;
                if (t->next)
                    t->right->next = t->next->left;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            Node* prev = NULL;
            while (size--)
            {
                Node* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (prev != NULL)
                    prev->next = curr;
                prev = curr;
            }
        }
        return root;

    }
};

class Solution {
public:
    void preorder(Node* root)
    {
        if (!root)
            return;
        if (root->left)
            root->left->next = root->right;
        if (root->right)
            root->right->next = (root->next) ? root->next->left : NULL;
        preorder(root->left);
        preorder(root->right);
    }
    Node* connect(Node* root) {
        preorder(root);
        return root;

    }
};