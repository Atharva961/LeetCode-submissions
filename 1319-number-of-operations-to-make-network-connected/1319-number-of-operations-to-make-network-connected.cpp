class Solution {
public:
    void print(vector<int>& v)
    {
        for(auto i:v)cout<<i<<",";
        cout<<endl;
    }
    void bfs(int n, vector<int>& visited, vector<vector<int>>& adj)
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
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
        if(v.size()<n-1)return -1;
        vector<vector<int>> adj(n+1);
        
        for(auto i:v)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> visited(n, 0);
        
        int ans = 0;
        while(true)
        {   
            // cout<<"A"<<endl;
            // print(visited);
            bool flag = false;
            for(int i=0; i<visited.size(); i++)
            {
                if(!visited[i])
                {
                    flag = true;
                    bfs(i, visited, adj);  
                    ans++;
                }
            }
            // print(visited);
            // cout<<"B"<<endl;
            if(!flag)break;
        }
        ans--;
        return ans;
    }
};