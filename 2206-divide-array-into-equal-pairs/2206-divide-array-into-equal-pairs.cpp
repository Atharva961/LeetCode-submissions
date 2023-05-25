class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> h(501, 0);
        for(int i:nums)h[i]++;
        for(int i:h)if(i%2!=0)return false;
        return true;
    }
};