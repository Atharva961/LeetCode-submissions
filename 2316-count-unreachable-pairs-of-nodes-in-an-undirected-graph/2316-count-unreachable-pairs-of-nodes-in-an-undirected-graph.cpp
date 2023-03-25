class Solution {
public:
    long long bfs(vector<vector<int>>& adj, int n, vector<int>& visited)
    {
        queue<int> q;
        q.push(n);
        visited[n] = 1;
        long long ans = 1;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            int count = 0;
            for(int i:adj[f])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    count++;
                }
            }
            adj[f].clear();
            ans+=count;
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(n, 0);
        vector<int> v;
        long long count = 0, ans = 0;
        for(int i=0; i<visited.size(); i++)
        {
            if(!visited[i])
            {
                long long temp = bfs(adj, i, visited);
                ans+=(temp*count);
                count+=temp;
            }
        }
        return ans;
    }
};