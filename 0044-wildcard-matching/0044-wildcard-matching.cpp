class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string& s, string& p, int i, int j)
    {
        if(i<0 && j<0)return true;
        if(j<0)return false;
        if(i<0)
        {
            for(int k=0; k<=j; k++)
            {
                if(p[k]!='*')return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='?')return dp[i][j] = solve(s, p, i-1, j-1);
        else if(p[j]=='*')
        {
            return dp[i][j] = solve(s, p, i-1, j)|| solve(s, p, i, j-1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(s, p, s.size()-1, p.size()-1);
    }
};