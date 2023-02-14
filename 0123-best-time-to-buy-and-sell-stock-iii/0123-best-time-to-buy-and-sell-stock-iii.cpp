class Solution {
public:
    int dp[2][100001][3];
    int solve(int n, int buy, vector<int>& prices, int limit)
    {
        if(n==prices.size())return 0;
        if(limit==0)return 0;
        
        if(dp[buy][n][limit]!=-1)return dp[buy][n][limit];
        
        int profit;
        
        if(buy)
        {
            int buy_price = -prices[n] + solve(n+1, !buy, prices, limit);
            int skip_price = solve(n+1, buy, prices, limit);
            profit = max(buy_price, skip_price);
        }
        else
        {
            int sell_price = prices[n] + solve(n+1, !buy, prices, limit-1);
            int skip_price = solve(n+1, buy, prices, limit);
            profit = max(sell_price, skip_price);
        }
        
        return dp[buy][n][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, prices, 2);
    }
};