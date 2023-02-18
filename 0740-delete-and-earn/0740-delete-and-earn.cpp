class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxx = 0;
        for(auto i:nums)maxx = max(i, maxx);
        vector<int> h(maxx+1, 0);
        for(auto i:nums)h[i]++;
        vector<int> dp(maxx+3, 0);
        int i0 = 0, i1 = 0, i2 = 0;
        
        for(int i=h.size()-1; i>=0; i--)
        {
            int ignore = i1;
            int del = 0;
            if(h[i]>0)
            {
                del = i*h[i] + i2;
            }
            i0 = max(ignore, del);
            i2 = i1;
            i1 = i0;
        }
        return i0;
    }
};