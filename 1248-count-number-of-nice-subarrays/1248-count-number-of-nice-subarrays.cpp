class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int ans = 0;
        map<int, int> m;
        m[0] = 1;
        for(auto i:nums)
        {
            if(i%2!=0)count++;
            m[count]++;
            ans+=m[count-k];
        }
        
        return ans;
    }
};