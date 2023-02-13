class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> m;
        for(auto i:nums)m[i]++;
        for(int i=1; i<=INT_MAX; i++)if(!m[i])return i;
        return -1;
    }
};