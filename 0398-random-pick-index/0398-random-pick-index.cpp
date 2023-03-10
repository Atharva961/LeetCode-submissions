class Solution {
public:
    map<int, vector<int>> m;
    Solution(vector<int>& nums) {
       for(int i=0; i<nums.size(); i++)
       {
           m[nums[i]].push_back(i);
       }
    }
    
    int pick(int target) {
        vector<int> v = m[target];
        return v[rand()%v.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */