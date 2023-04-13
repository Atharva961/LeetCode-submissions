class Solution {
public:
    int solve(int n, int i, vector<vector<int>>& dp)
    {
        if(n<=0 || i==0)return 1;
        if(i>n)return solve(n, i-1, dp);
        
        if(dp[n][i]!=-1)return dp[n][i];
        
        int include = i*solve(n-i, i, dp);
        int exclude = solve(n, i-1, dp);
        
        return dp[n][i] = max(include, exclude);
    }
    
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, n-1, dp);
    }
};