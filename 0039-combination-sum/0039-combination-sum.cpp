class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& v, int index, int sum, vector<int>& temp, int target)
    {
        if(sum>target)return;
        if(sum==target)
        {
            // cout<<sum<<endl;
            s.insert(temp);
            return;
        }
        if(index>=v.size())return;
        
        //include
        vector<int> pass = temp;
        pass.push_back(v[index]);
        
        solve(v, index, sum+v[index], pass, target);
        
        //exclude
        solve(v, index+1, sum, temp, target);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, 0, 0, temp, target);
        vector<vector<int>> ans(s.begin(), s.end());
        
        return ans;
    }
};