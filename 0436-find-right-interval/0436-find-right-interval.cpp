class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> v;
        map<int, int> m;
        
        for(int i=0; i<intervals.size(); i++)
        {
            v.push_back(intervals[i][0]);
            m[intervals[i][0]] = i;
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        
        for(auto i:intervals)
        {
            int ind = lower_bound(v.begin(), v.end(), i[1]) - v.begin();
            ans.push_back(ind==v.size()?-1:m[v[ind]]);
        }
        
        return ans;
    }
};