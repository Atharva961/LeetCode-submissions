class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int prev, int curr)
    {
        if(curr==nums.size())return 0;
        if(dp[prev+1][curr]!=-1)return dp[prev+1][curr];
        int include = 0;
        if(prev==-1 ||nums[curr]>nums[prev])
        {
            include = 1 + solve(nums, curr, curr+1);
        }
        int exclude = solve(nums, prev, curr+1);
        return dp[prev+1][curr] = max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size()+2, vector<int>(nums.size()+1, -1));
        return solve(nums, -1, 0);
    }
};