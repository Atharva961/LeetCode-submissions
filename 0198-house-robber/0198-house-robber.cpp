class Solution {
public:
    int rob(vector<int>& nums) {
        int i2 = 0, i1 = 0, i0 = 0;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            int rob = nums[i] + i2;
            int ignore = i1;
            i0 = max(rob, ignore);
            i2 = i1;
            i1 = i0;
        }
        
        return i0;
    }
};