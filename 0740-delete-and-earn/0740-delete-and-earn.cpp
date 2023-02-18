class Solution {
public:
    int solve(vector<int>& h, int index, vector<int>& dp)
    {
        if(index>=h.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int ignore = solve(h, index+1, dp);
        int del = 0;
        if(h[index]>0)
        {
            del = index*h[index] + solve(h, index+2, dp);
        }
        return dp[index] = max(ignore, del);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxx = 0;
        for(auto i:nums)maxx = max(i, maxx);
        vector<int> h(maxx+1, 0);
        for(auto i:nums)h[i]++;
        vector<int> dp(maxx+1, -1);
        return solve(h, 0, dp);
    }
};