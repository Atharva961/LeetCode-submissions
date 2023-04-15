class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp)
    {
        if (dp[i][k] > 0) return dp[i][k];
        if (i == piles.size() || k == 0) return 0;
        int ans = solve(i + 1, k, piles, dp), cur = 0;
        for (int j = 0; j < piles[i].size() && j < k; ++j) {
            cur += piles[i][j];
            ans = max(ans, solve(i + 1, k - j - 1, piles, dp) + cur);
        }
        dp[i][k] = ans;
        return ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size()+1, vector<int>(k+1, -1));
        return solve( 0, k,piles, dp);
    }
};