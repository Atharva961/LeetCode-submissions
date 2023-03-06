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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<int>> m;
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode * curr = q.front();
            q.pop();
            if(curr==NULL)
            {
                level++;
            }
            else
            {
                m[level].push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                if(q.front()==NULL)q.push(NULL);
            }
        }
        
        vector<vector<int>> ans;
        for(auto i:m)ans.push_back(i.second);
        return ans;
    }
};