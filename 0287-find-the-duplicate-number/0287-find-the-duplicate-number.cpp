class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(auto i:nums)
        {
            if(m[i])return i;
            m[i]++;
        }
        return -1;
    }
};