class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& candidates, int target, vector<int>& v, int index, int sum)
    {
        if(index==candidates.size())return;
        if(sum==target)
        {
            s.insert(v);
            return;
        }
        if(sum>target)return;
        vector<int> inc = v;
        inc.push_back(candidates[index]);
        solve(candidates, target, inc, index, sum+candidates[index]);
        solve(candidates, target, v, index+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(candidates, target, v, 0, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};