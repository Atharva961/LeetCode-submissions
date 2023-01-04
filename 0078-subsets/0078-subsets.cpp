class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int> nums, vector<int>& v, int ind)
    {
        s.insert(v);
        if(ind>=nums.size())return;
    
        vector<int> inc = v;
        inc.push_back(nums[ind]);
        
        //include
        solve(nums, inc, ind+1);
        //exclude
        solve(nums, v, ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v = {};
        solve(nums, v, 0);
        
        vector<vector<int>> ans(s.begin(), s.end());
        
        return ans;
    }
};