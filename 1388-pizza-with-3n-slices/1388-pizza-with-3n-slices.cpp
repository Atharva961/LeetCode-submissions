class Solution {
public:
    int solve(vector<int>& v, int index, int n, vector<vector<int>>& dp)
    {
        if(n==0)return 0;
        if(index>=v.size())return 0;
        if(dp[index][n]!=-1)return dp[index][n];
        int include = v[index] + solve(v, index+2, n-1, dp);
        int exclude = solve(v, index+1, n, dp);
        return dp[index][n] = max(include, exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(slices.size()+1, vector<int>(n+1, -1)), dp2(slices.size()+1, vector<int>(n+1, -1));
        int ans1 = solve(slices, 1, n/3, dp1);
        slices.pop_back();
        int ans2 = slices[0] + solve(slices, 2, n/3-1, dp2);
        return max(ans1, ans2);
    }
};