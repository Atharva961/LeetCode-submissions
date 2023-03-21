class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int beg = 0;
        for(int end = 0; end<nums.size(); end++)
        {
            if(nums[end]!=0)beg = end+1;
            ans+=(end-beg+1);
        }
        return ans;
    }
};