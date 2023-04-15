class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& piles, int index, int k)
    {
        if(index==piles.size() || k==0)return 0;
        if(dp[index][k]!=-1)return dp[index][k];
        int ans = solve(piles, index+1, k);
        
        int sum = 0;
        for(int j=0; j<piles[index].size() && j<k; j++)
        {
            sum+=piles[index][j];
            ans = max(ans, sum + solve(piles, index+1, k-j-1));
        }
        
        return dp[index][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp = vector<vector<int>>(piles.size()+1, vector<int>(k+1, -1));
        return solve(piles, 0, k);
    }
};