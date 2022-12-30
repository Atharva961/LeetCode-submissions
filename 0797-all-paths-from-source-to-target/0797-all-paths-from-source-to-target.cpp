class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<vector<int>>& graph, int index, vector<int>& path, int dest)
    {
        path.push_back(index);
        // visited[index] = 1;
        if(index==dest)
        {
            ans.push_back(path);
            return;
        }
        
        for(int i=0; i<graph[index].size(); i++)
        {
            vector<int> temp = path;
            solve(graph, graph[index][i], temp, dest);
        }
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        // vector<int> visited(graph.size(), 0);
        solve(graph, 0, path, graph.size()-1);
        return ans;
    }
};