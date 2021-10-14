/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, int level, int &maxLevel)
    {
        if (!root)
            return ;
        maxLevel = max(level, maxLevel);
        for (auto neighbour : root->children)
            solve(neighbour, level + 1, maxLevel);
    }
    int maxDepth(Node* root) {
        int level = 0, maxLevel = 0;
        if (!root)
            return 0;
        solve(root, level, maxLevel);
        return maxLevel + 1;

    }
};