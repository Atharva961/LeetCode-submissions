class Solution {
public:
    int minLength(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            ans.push_back(s[i]);
            if(ans.size()>=2 && (ans.substr(ans.size()-2)=="AB" || ans.substr(ans.size()-2)=="CD"))
            {
                ans.pop_back();
                ans.pop_back();
            }
        }
        return ans.size();
    }
};