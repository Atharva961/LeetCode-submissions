class Solution {
public:
    vector<vector<int>> dp;
    bool check(vector<vector<int>>& v, int prev, int index)
    {
        if(v[prev][0]<=v[index][0] && v[prev][1]<=v[index][1] && v[prev][2]<=v[index][2])return true;
        return false;
    }
    int solve(vector<vector<int>>& v, int prev, int index)
    {
        if(index>=v.size())return 0;
        if(dp[prev+1][index]!=-1)return dp[prev+1][index];
        int include = 0;
        if(prev==-1 || check(v, prev, index))
        {
            include = v[index][2] + solve(v, index, index+1);
        }
        int exclude = solve(v, prev, index+1);
        return dp[prev+1][index] = max(include, exclude);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i:cuboids)sort(i.begin(), i.end());
        sort(cuboids.begin(), cuboids.end());
        dp = vector<vector<int>>(cuboids.size()+2, vector<int>(cuboids.size()+2, -1));
        return solve(cuboids, -1, 0);
    }
};