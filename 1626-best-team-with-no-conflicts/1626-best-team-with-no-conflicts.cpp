class Solution {
public:
    int solve(vector<vector<int>>& v, int index, int age, vector<vector<int>>& dp)
    {
        if(index>=v.size())return 0;
        if(dp[index][age]!=-1)return dp[index][age];
        int include = 0, exclude;
        if(v[index][1]>=age)include = v[index][0] + solve(v, index+1, max(age, v[index][1]), dp);
        exclude = solve(v, index+1, age, dp);
        return dp[index][age] = max(include, exclude);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> v;
        for(int i=0; i<scores.size(); i++)v.push_back({scores[i], ages[i]});
        sort(v.begin(), v.end());
        vector<vector<int>> dp(scores.size()+1, vector<int>(1001, -1));
        return solve(v, 0, 0, dp);
    }
};