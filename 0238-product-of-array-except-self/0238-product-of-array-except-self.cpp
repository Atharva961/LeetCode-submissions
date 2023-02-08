class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fwd = {1}, bwd = {1};
        for(int i=0; i<nums.size(); i++)fwd.push_back(fwd[fwd.size()-1]*nums[i]);
        for(int i=nums.size()-1; i>=0; i--)bwd.push_back(bwd[bwd.size()-1]*nums[i]);
        reverse(bwd.begin(), bwd.end());
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)ans.push_back(fwd[i]*bwd[i+1]);
        return ans;
    }
};