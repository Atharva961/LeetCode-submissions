class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> h(graph.size(), 0);
        queue<int> q;
        for(int i=0; i<graph.size(); i++)
        {
            if(h[i])continue;
            h[i] = 1;
            q.push(i);
            while(!q.empty())
            {
                int f = q.front();
                for(int j:graph[f])
                {
                    if(!h[j])
                    {
                        h[j] = -h[f];
                        q.push(j);
                    }
                    else if(h[f]==h[j])
                    {
                        return false;
                    }
                }
                q.pop();
            }
        }
        
        return true;
    }
};