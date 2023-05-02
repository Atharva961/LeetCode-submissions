class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool pos = true;
        for(int i:nums)
        {
            if(i==0)return 0;
            if(i<0)pos = !pos;
        }
        return pos?1:-1;
    }
};