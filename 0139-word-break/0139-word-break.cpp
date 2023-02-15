class Solution {
public:
    vector<string> v;
    bool solve(string& s, int prev, int index, vector<vector<int>>& dp)
    {
        string word = s.substr(prev, index-prev);
        // cout<<index<<","<<word<<endl;
        if(index==s.size())
        {
            if(word=="" || binary_search(v.begin(), v.end(), word))return true;
            return false;
        }
        
        if(dp[prev][index]!=-1)return dp[prev][index];
        bool inc, brk = false;
        if(binary_search(v.begin(), v.end(), word))brk = solve(s, index, index+1, dp);
        inc = solve(s, prev, index+1, dp);
        
        return dp[prev][index] = inc||brk;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        this->v = wordDict;
        return solve(s, 0, 0, dp);
    }
};