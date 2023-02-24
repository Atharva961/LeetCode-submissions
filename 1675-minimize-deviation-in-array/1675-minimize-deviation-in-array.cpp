class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX, minn = INT_MAX;
        set<int> s;
        for(auto i:nums)
        {
            minn = min(i, minn);
            if(i%2==0)s.insert(i);
            else s.insert(i*2);
        }
        
        ans = *s.rbegin() - *s.begin();
        
        while(*s.rbegin()%2==0)
        {
            int t = *s.rbegin();
            s.erase(t);
            t/=2;
            s.insert(t);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        
        return ans;
    }
};