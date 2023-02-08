class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index>=nums.size()-1)return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = 100001;
        for(int i=1; i<=nums[index]; i++)ans = min(ans, 1 + solve(nums, index+i, dp));
        return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};