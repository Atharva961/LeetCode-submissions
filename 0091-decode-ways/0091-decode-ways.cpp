class Solution {
public:
    int dp[101];
    int solve(string s, int index)
    {
        if(s[index]=='0')return 0;
        if(index>=s.size()-1)return 1;
        
        if(dp[index]!=-1)return dp[index];
            
        int one_digit = solve(s, index+1);
        int two_digit = 0;
        if((s[index]-'0')*10 + (s[index+1]-'0')<=26)two_digit = solve(s, index+2);
        return dp[index] = one_digit + two_digit;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};