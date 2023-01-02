class Solution {
public:
    vector<int> pfs(int n)
    {
        vector<int> ans;
        int d = 2;
        while(n>1)
        {
            if(n%d==0)
            {
                ans.push_back(d);
                n/=d;
            }
            else d++;
        }
        
        return ans;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        
        set<int> s;
        
        for(auto i:nums)
        {
            vector<int> temp = pfs(i);
            for(auto j:temp)s.insert(j);
        }
        
        return s.size();
    }
};