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
    map<int, Node*> m;
    void solve(Node* root, int level)
    {
        if(!root)return;
        if(m[level])m[level]->next = root;
        m[level] = root;
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    Node* connect(Node* root) {
        solve(root, 0);
        return root;
    }
};