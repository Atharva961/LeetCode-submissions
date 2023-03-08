class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        bool dp[n+1][n+1];
        memset(dp, false ,sizeof(dp));
        dp[0][1] = true;
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int dist = stones[i] - stones[j];
                if(dist>0 && dist<n && dp[j][dist])
                {
                    if(i==n-1)return true;
                    dp[i][dist] = true;
                    if(dist+1<n)dp[i][dist+1] = true;
                    if(dist-1<n)dp[i][dist-1] = true;
                }
            }
        }
        return false;
    }
};