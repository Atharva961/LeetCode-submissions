class Solution {
public:
    vector<int> solve(vector<int>& a, vector<int>& b)
    {
        unordered_map<int, int> m;
        set<int> s;
        for(int i:a)m[i]++;
        for(int i:b)
        {
            if(!m[i])s.insert(i);
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        ans.push_back(solve(nums2, nums1));
        ans.push_back(solve(nums1, nums2));
        return ans;
    }
};