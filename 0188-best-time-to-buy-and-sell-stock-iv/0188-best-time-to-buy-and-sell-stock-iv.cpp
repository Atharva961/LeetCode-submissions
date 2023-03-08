class Solution {
public:
    // int solve(vector<int>& prices, int index, bool buy, int k)
    // {
    //     if(k==0)return 0;
    //     if(index==prices.size())return 0;
    //     if(buy)
    //     {
    //         int buy = -prices[index] + solve(prices, index+1, false, k);
    //         int ignore = solve(prices, index+1, buy, k);
    //         return max(buy, ignore);
    //     }
    //     else
    //     {
    //         int sell = prices[index] + solve(prices, index+1, true, k-1);
    //         int ignore = solve(prices, index+1, buy, k);
    //         return max(sell, ignore);
    //     }
    //     return 0;
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     return solve(prices, 0, true, k);
    // }
    int dp[1001][2][101];
    int solve(int n, int buy, int k, vector<int>& prices)
    {
        if(n==prices.size())return 0;
        if(k==0)return 0;
        
        if(dp[n][buy][k]!=-1)return dp[n][buy][k];
        
        int profit;
        
        if(buy)
        {
            int buy_price = -prices[n] + solve(n+1, !buy, k, prices);
            int skip_price = solve(n+1, buy, k, prices);
            profit = max(buy_price, skip_price);
        }
        else
        {
            int sell_price = prices[n] + solve(n+1, !buy, k-1, prices);
            int skip_price = solve(n+1, buy, k, prices);
            profit = max(sell_price, skip_price);
        }
        
        return dp[n][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, k, prices);
    }
};