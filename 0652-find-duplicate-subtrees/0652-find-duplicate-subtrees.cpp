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
    map<string, vector<TreeNode *> > m;
    string solve(TreeNode * root)
    {
        if(!root)return "";
        string ans = "(" + solve(root->left) + to_string(root->val) + solve(root->right) + ")";
        m[ans].push_back(root);
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        vector<TreeNode *> ans;
        for(auto i:m)
        {
            if(i.second.size()>1)
            {
                ans.push_back(i.second[0]);
            }
        }
        
        return ans;
    }
};