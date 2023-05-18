class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v(n, 0);
        for(auto i:edges)v[i[1]] = 1;
        vector<int> ans;
        for(int i=0; i<v.size(); i++)if(v[i]==0)ans.push_back(i);
        return ans;
    }
};