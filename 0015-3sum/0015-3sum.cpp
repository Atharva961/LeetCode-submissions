class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            int sum = nums[i];
            int target = 0 - sum;
            int beg = i+1, end = nums.size()-1;
            
            while(beg<end)
            {
                int t_sum = nums[beg] + nums[end];
                if(t_sum==target)
                {
                    ans.insert({nums[i], nums[beg], nums[end]});
                    beg++;
                    end--;
                }
                else if(t_sum>target)
                {
                    end--;
                }
                else beg++;
            }
        }
        
        vector<vector<int>> anss(ans.begin(), ans.end());
        
        return anss;
    }
};