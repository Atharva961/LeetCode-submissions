class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minn = INT_MAX;
        for(int i:nums)minn = min(minn, i);
        int ans = 0;
        for(int i:nums)ans+=(i-minn);
        return ans;
    }
};