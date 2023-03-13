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
    void flipTree(TreeNode * root)
    {
        if(root)
        {
            swap(root->left, root->right);
            flipTree(root->left);
            flipTree(root->right);
        }
    }
    bool sameTree(TreeNode * a, TreeNode * b)
    {
        if(!a && !b)return true;
        if(!a || !b)return false;
        if(a->val != b->val)return false;
        return true && sameTree(a->left, b->left) && sameTree(a->right, b->right);
    }
    bool isSymmetric(TreeNode* root) {
        flipTree(root->right);
        return sameTree(root->left, root->right);
    }
};