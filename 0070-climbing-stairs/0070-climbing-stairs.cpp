class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp = {0, 1, 2};
        for(int i=3; i<=n; i++)dp.push_back(dp[i-1] + dp[i-2]);
        return dp[n];
    }
};