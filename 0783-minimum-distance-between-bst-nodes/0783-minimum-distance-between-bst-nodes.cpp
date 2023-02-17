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
    int prev = -100001, curr = -100001;
    int ans = INT_MAX;
    void inorder(TreeNode * root)
    {
        if(root)
        {
            inorder(root->left);
            prev = curr;
            curr = root->val;
            printf("(%d, %d)\n", prev, curr);
            ans = min(ans, curr-prev);
            inorder(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};