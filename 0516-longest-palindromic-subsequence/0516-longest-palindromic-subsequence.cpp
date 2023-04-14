class Solution {
public:
    int lcs(string& a, string& b)
    {
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
        
        for(int i=0; i<=a.size(); i++)
        {
            for(int j=0; j<=b.size(); j++)
            {
                if(i==0 || j==0)dp[i][j] = 0;
                else if(a[i-1]==b[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[a.size()][b.size()];
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return lcs(s, r);
    }
};