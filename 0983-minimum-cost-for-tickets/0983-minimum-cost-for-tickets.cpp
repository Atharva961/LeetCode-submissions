class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& days, vector<int>& costs, int index)
    {
        if(index>=days.size())return 0;
        if(dp[index]!=-1)return dp[index];
        
        int one = costs[0] + solve(days, costs, index+1);
        int c7 = days[index] + 7;
        int p7 = lower_bound(days.begin(), days.end(), c7) - days.begin();
        
        int seven = costs[1] + solve(days, costs, p7);
        int c30 = days[index] + 30;
        int p30 = lower_bound(days.begin(), days.end(), c30) - days.begin();
        
        int thirty = costs[2] + solve(days, costs, p30);
        
        return dp[index] = min(one, min(seven, thirty));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        dp = vector<int>(days.size()+1, -1);
        return solve(days, costs, 0);
    }
};