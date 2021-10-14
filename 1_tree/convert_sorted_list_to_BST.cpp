/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    struct LNode* next;

    LNode(int x) {
        data = x;
        next = NULL;
    }
};

struct TNode
{

    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

TNode* sortedListToBST(LNode* head);

void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        TNode* Thead = sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";

    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++


//User function Template for C++

/*
//Linked List
struct LNode
{
    int data;
    struct LNode* next;

    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode
{

    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */

TNode* buildTree(vector<int> &r, int low, int high)
{
    if (low > high)
        return NULL;
    int ele = high - low + 1;
    int mid = low + ele / 2;

    TNode* root = new TNode(r[mid]);
    root->left = buildTree(r, low, mid - 1);
    root->right = buildTree(r, mid + 1, high);
    return root;
}

TNode* sortedListToBST(LNode *head)
{
    //code here
    vector<int> r;
    while (head)
    {
        r.push_back(head->data);
        head = head->next;
    }
    return buildTree(r, 0, r.size() - 1);
}
class Solution {
public:
    TreeNode* buildTree(vector<int> r, int low, int high)
    {
        if (low > high)
            return NULL;
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(r[mid]);
        root->left = buildTree(r, low, mid - 1);
        root->right = buildTree(r, mid + 1, high);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        vector<int> r;
        while (head)
        {
            r.push_back(head->val);
            head = head->next;
        }
        return buildTree(r, 0, r.size() - 1);

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* solve(ListNode* head, ListNode* tail)
{
    if (head == tail)
        return NULL;
    if (head->next == tail)
    {
        TreeNode* root = new TreeNode(head->val);
        return root;
    }
    ListNode* mid = head;
    ListNode* fast = head;
    while (fast != tail and fast->next != tail)
    {
        mid = mid->next;
        fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(mid->val);
    root->left = solve(head, mid);
    root->right = solve(mid->next, tail);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return solve(A, NULL);
}
