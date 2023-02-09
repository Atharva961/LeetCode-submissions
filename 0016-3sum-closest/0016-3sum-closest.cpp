class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX, ans;
        for(int i=0; i<nums.size(); i++)
        {
            int s1 = nums[i];
            int beg = i+1, end = nums.size()-1;
            while(beg<end)
            {
                int sum = s1 + nums[beg] + nums[end];
                if(sum==target)return sum;
                if(abs(sum-target)<min_diff)
                {
                    ans = sum;
                    min_diff = abs(sum-target);
                }
                if(sum>target)end--;
                else beg++;
            }
        }
        return ans;
    }
};