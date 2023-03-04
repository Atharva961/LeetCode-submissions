class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1;
        map<int, int> m;
        set<int> s;
        int beg = 0, end = 0;
        while(end<nums.size())
        {
            m[nums[end]]++;
            s.insert(nums[end]);
            while(*s.rbegin()-*s.begin()>limit && beg<end)
            {
                m[nums[beg]]--;
                if(m[nums[beg]]==0)
                {
                    s.erase(nums[beg]);
                }
                beg++;
            }
            ans = max(ans, end-beg+1);
            end++;
        }
        
        return ans;
    }
};