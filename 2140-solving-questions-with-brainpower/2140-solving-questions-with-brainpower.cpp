class Solution {
public:
    long long solver(vector<vector<int>>& v, int index, vector<long long>& dp)
    {
        if(index>=v.size())return 0;
        if(dp[index]!=-1)return dp[index];
        long long solve = v[index][0] + solver(v, index+v[index][1]+1, dp);
        long long skip = solver(v, index+1, dp);
        return dp[index] = max(solve, skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1, -1);
        return solver(questions, 0, dp);
    }
};