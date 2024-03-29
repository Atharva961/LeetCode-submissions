class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int sum = 0, max_sum = nums[0];
        
        for(int i=0; i<nums.size(); i++)
        {
            sum = max(nums[i], sum+nums[i]);
            max_sum = max(max_sum, sum);
        }
        
        return max_sum;
    }
};