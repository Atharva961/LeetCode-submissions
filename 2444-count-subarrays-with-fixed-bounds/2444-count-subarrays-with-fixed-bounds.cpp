class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int imin = -1, imax = -1, ibad = -1;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<minK || nums[i]>maxK)ibad = i;
            if(nums[i]==maxK)imax = i;
            if(nums[i]==minK)imin = i;
            if(min(imin, imax)-ibad>=0)
            {
                ans+=(min(imin, imax)-ibad);
            }
        }
        return ans;
    }
};