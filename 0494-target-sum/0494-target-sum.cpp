class Solution {
public:
    int solve(vector<int>& nums, int index, int target)
    {
        if(index==nums.size())
        {
            if(target==0)return 1;
            return 0;
        }

        
        //positive
        int positive = solve(nums, index+1, target-nums[index]);
        //negative
        int negative = solve(nums, index+1, target+nums[index]);
        
        return positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};