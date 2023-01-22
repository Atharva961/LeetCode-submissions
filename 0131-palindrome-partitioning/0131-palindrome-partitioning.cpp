class Solution {
public:
    set<vector<string>> ans;
    bool isPalindrome(string& s)
    {
        if(s.size()==0)return false;
        int beg = 0, end = s.size()-1;
        while(beg<end)
        {
            if(s[beg]!=s[end])return false;
            beg++;
            end--;
        }
        return true;
    }
    void solve(string& s, vector<string>& v, string temp, int ind, int len)
    {
        if(ind==s.size())
        {
            if(len==s.size())ans.insert(v);
            return;
        }
        temp.push_back(s[ind]);
        
        if(isPalindrome(temp))
        {
            vector<string> i = v;
            i.push_back(temp);
            solve(s, i, "", ind+1, len+temp.size());
        }
        solve(s, v, temp, ind+1, len);
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s, v, "", 0, 0);
        vector<vector<string>> anss(ans.begin(), ans.end());
        return anss;
    }
};