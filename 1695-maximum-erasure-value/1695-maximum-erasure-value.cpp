class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int beg = 0, end = 0;
        int sum = 0, ans = 0;
        map<int, int> m;
        
        while(end<nums.size())
        {
            sum+=nums[end];
            m[nums[end]]++;
            while(m[nums[end]]>=2)
            {
                m[nums[beg]]--;
                sum-=nums[beg];
                beg++;
            }
            ans = max(ans, sum);
            end++;
        }
        return ans;
    }
};