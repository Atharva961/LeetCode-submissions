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
class Solution {
public:
    unordered_map<int, int> m;
    int value(TreeNode * root)
    {
        if(!root)return 0;
        return root->val;
    }
    void sum(TreeNode * root, int level)
    {
        if(!root)return;
        m[level]+=root->val;
        sum(root->left, level+1);
        sum(root->right, level+1);
    }
    void solve(TreeNode * root, int level)
    {
        if(!root)return;
        int assign = m[level+1] - value(root->left) - value(root->right);
        if(root->left)root->left->val = assign;
        if(root->right)root->right->val = assign;
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        sum(root, 0);
        solve(root, 0);
        root->val = 0;
        return root;
    }
};