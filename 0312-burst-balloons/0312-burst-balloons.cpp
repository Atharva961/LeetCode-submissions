class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums, int i, int j)
    {
        if(i>j)return 0;
        if(i==j)
        {
            int ans = nums[i];
            if(i-1>=0)ans*=nums[i-1];
            if(i+1<nums.size())ans*=nums[j+1];
            return ans;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        for(int k=i; k<=j; k++)
        {
            int temp = nums[k];
            if(i-1>=0)temp*=nums[i-1];
            if(j+1<nums.size())temp*=nums[j+1];
            temp+=solve(nums, i, k-1);
            temp+=solve(nums, k+1, j);
            ans = max(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<int> arr = {1};
        for(int i:nums)arr.push_back(i);
        arr.push_back(1);
        return solve(arr, 1, arr.size()-2);
    }
};