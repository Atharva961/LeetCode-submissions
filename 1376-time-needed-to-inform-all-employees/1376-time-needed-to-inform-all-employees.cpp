class Solution {
public:
    int dfs(vector<int>& manager, vector<int>& informTime, int index)
    {
        if(manager[index]!=-1)
        {
            informTime[index] += dfs(manager, informTime, manager[index]);
            manager[index] = -1;
        }
        return informTime[index];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        for(int i=0; i<n; i++)ans = max(ans, dfs(manager, informTime, i));
        return ans;
    }
};