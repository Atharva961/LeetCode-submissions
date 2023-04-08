class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<=nums.size(); i++)sum+=i;
        for(int i:nums)sum-=i;
        return sum;
    }
};