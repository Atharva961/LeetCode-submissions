class Solution {
public:
    set<string> v;
    void solve(string s, string& temp, int num, int ind, int count)
    {
        if(ind==s.size())
        {
            // temp+=to_string(num);
            if(count==4 && temp.size()==(s.size()+3))v.insert(temp);
            return;
        }
        if(count>4)return;
        
        num = num*10 + (s[ind]-'0');
        if(num>255)return;
        
        string inc = temp;
        if(inc.size()!=0)inc.push_back('.');
        inc+=to_string(num);
        
        solve(s, inc, 0, ind+1, count+1);
        solve(s, temp, num, ind+1, count);
    }
    vector<string> restoreIpAddresses(string s) {
        string temp;
        solve(s, temp, 0, 0, 0);
        vector<string> ans(v.begin(), v.end());
        
        return ans;
    }
};