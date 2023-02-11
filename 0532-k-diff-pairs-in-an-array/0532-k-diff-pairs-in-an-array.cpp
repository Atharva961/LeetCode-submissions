class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<vector<int>> s;
        map<int, int> m;
        for(auto i:nums)m[i]++;
        for(auto i:nums)
        {
            if(k!=0)
            {
                if(m[i-k])s.insert({i-k, i});
                if(m[i+k])s.insert({i, i+k});
            }
            if(k==0)
            {
                if(m[i]>1)s.insert({i, i});
            }
        }
        return s.size();
    }
};