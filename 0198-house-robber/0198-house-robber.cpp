class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int index)
    {
        if(index>=nums.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int rob = nums[index] + solve(nums, index+2);
        int ignore = solve(nums, index+1);
        
        return dp[index] = max(rob, ignore);
    }
    int rob(vector<int>& nums) {
        dp = vector<int>(nums.size()+1, -1);
        return solve(nums, 0);
    }
};