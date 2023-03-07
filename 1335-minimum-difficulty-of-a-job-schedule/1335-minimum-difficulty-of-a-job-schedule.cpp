class Solution {
public:
    int dp[301][11];
    int solve(vector<int>& v, int index, int d)
    {
        if(index==v.size() && d==0)return 0;
        if(d<=0)return INT_MAX;
        if(dp[index][d]!=-1)return dp[index][d];
        int ans = INT_MAX, maxx = 0;
        
        for(int i=index; i<v.size(); i++)
        {
            maxx = max(maxx, v[i]);
            int temp = solve(v, i+1, d-1);
            if(temp!=INT_MAX)ans = min(ans, maxx + temp);
        }
        
        return dp[index][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp));
        if(d>jobDifficulty.size())return -1;
        return solve(jobDifficulty, 0, d);
    }
};