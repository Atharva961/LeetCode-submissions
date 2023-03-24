class Solution {
public:
    int minReorder(int n, vector<vector<int>>& arr) {
        // sort(arr.begin(), arr.end());
        set<vector<int>> s(arr.begin(), arr.end());
        vector<vector<int>> adj(n);
        for(auto i:arr)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int ans = 0;
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(int i:adj[f])
            {
                if(!visited[i])
                {
                    if(s.find({f, i})!=s.end())ans++;
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};