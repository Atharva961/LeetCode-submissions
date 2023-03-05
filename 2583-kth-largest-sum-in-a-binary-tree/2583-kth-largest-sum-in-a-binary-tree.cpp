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
    map<int, long long> m;
    void solve(TreeNode * root, int level)
    {
        if(!root)return;
        m[level]+=root->val;
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        solve(root, 0);
        priority_queue<long long> q;
        for(auto i:m)
        {
            q.push(i.second);
        }
        while(k>1)
        {
            q.pop();
            if(q.empty())return -1;
            k--;
        }
        return q.top();
    }
};