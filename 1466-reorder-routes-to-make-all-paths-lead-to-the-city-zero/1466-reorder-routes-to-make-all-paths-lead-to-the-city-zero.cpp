class Solution {
public:
    int minReorder(int n, vector<vector<int>>& arr) {
        set<vector<int>> s(arr.begin(), arr.end());// for searching purpose.
		
		//Make adjacency list like for a undirected graph.
        vector<vector<int>> adj(n);
        for(auto i:arr)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int ans = 0;
        queue<int> q;
        vector<int> visited(n, 0);
		
		//Start BFS from 0
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
					// Basically we are moving away from 0 in BFS. 
					//So if there is a directed edge from current node(f) to next node(i), there is an edge pointing away from 0, in that case increment ans by 1.
                    if(s.find({f, i})!=s.end())ans++;
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};