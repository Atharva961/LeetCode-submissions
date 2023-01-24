class Solution {
public:
    set<vector<int>> s;
    
    void solve(vector<int>& nums, int index, vector<int>& temp)
    {
        if(index==nums.size())
        {
            if(temp.size()==nums.size())s.insert(temp);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=-11)
            {
                vector<int> p_nums = nums;
                p_nums[i] = -11;
                vector<int> p_temp = temp;
                p_temp.push_back(nums[i]);
                
                solve(p_nums, index+1, p_temp);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        
        vector<vector<int>> ans(s.begin(), s.end());
        
        return ans;
    }
};