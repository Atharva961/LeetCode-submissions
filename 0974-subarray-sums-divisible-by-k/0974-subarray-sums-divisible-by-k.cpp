class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        map<int, int> m;
        m[0]++;
        
        for(auto i:nums)
        {
            sum+=i;
            ans+=m[(sum%k + k)%k];
            m[(sum%k + k)%k]++;
        }
        
        return ans;
    }
};