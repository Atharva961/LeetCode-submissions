class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(i<=farthest)farthest = max(farthest, i + nums[i]);
        }
        return farthest>=nums.size()-1;
    }
};