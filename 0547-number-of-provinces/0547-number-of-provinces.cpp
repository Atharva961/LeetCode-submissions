class Solution {
public:
    void bfs(vector<vector<int>>& adj, int n, vector<int>& visited)
    {
        queue<int> q;
        q.push(n);
        visited[n] = 1;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(int i:adj[f])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(n, 0);
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                ans++;
                bfs(adj, i, visited);
            }
        }
        
        return ans;
    }
};