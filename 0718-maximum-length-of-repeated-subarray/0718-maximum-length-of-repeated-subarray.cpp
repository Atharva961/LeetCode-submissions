class Solution {
public:
    int solve(vector<int>& a, vector<int>& b)
    {
        int n = a.size(), m = b.size();

        int dp[n+1][m+1];
        int ma = 0;

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0||j==0)dp[i][j] = 0;
                else if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j]>ma)
                    {
                        ma = dp[i][j];
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ma;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1, nums2);
    }
};