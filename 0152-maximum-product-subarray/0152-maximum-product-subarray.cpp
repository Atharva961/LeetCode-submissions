class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1, ans = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(prod==0)prod = 1;
            prod*=nums[i];
            ans = max(ans, prod);
        }
        prod = 1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(prod==0)prod = 1;
            prod*=nums[i];
            ans = max(ans, prod);
        }
        return ans;
    }
};