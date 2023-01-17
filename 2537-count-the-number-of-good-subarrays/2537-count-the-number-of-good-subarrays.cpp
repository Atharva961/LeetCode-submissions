class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int beg = 0, end = 0;
        long long ans = 0, pairs = 0;
        
        map<int, int> m;
        
        while(end<nums.size())
        {
            m[nums[end]]++;
            pairs+=m[nums[end]]-1;
            
            while(pairs>=k && beg<end)
            {
                ans+=nums.size()-end;
                m[nums[beg]]--;
                pairs-=m[nums[beg]];
                beg++;
            }
            end++;
        }
        
        return ans;
    }
};