class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        int maxx = 0;
        for(auto i:nums)maxx = max(i, maxx);
        vector<int> h(maxx+1, 0);
        for(auto i:nums)h[i]++;
        vector<int> dp(maxx+3, 0);
        
        for(int i=h.size()-1; i>=0; i--)
        {
            int ignore = dp[i+1];
            int del = 0;
            if(h[i]>0)
            {
                del = i*h[i] + dp[i+2];
            }
            dp[i] = max(ignore, del);
        }
        return dp[0];
    }
};