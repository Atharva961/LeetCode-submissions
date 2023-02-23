class Solution {
public:
    int dp[11][5001];
    int mod = 1000000007;
    int solve(vector<vector<int>>& v, int index, int k)
    {
        if(k==0)return 1;
        if(dp[index][k]!=-1)return dp[index][k];
        int ans = 0;
        for(int i:v[index])
        {
            ans = (ans%mod + solve(v, i, k-1)%mod)%mod;
        }
        return dp[index][k] = ans;
    }
    int knightDialer(int k) {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> v = {{4,6},{8,6},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4},{4,6}};
        int ans = 0;
        k--;
        if(k==0)return 10;
        for(int i=0; i<10; i++)
        {
            if(i==5)continue;
            ans = (ans%mod + solve(v, i, k)%mod)%mod;
        }
        return ans;
    }
};