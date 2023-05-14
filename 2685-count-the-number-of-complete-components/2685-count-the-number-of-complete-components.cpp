class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj, int n, vector<int>& visited)
    {
        vector<int> ans;
        queue<int> q;
        q.push(n);
        ans.push_back(n);
        visited[n] = true;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(int i:adj[f])
            {
                if(!visited[i])
                {
                    ans.push_back(i);
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return ans;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        vector<vector<int>> islands;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0; i<visited.size(); i++)
        {
            if(!visited[i])
            {
                islands.push_back(bfs(adj, i, visited));
            }
        }
        int ans = 0;
        for(auto i:islands)
        {
            bool flag = true;
            for(int j:i)
            {
                // cout<<j<<" ";
                if(adj[j].size()!=i.size()-1)flag = false;
            }
            // cout<<endl;
            if(flag)ans++;
        }
        return ans;
    }
};