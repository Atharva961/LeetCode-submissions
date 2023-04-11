class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            bool flag = true;
            while(ans.size() && ans[ans.size()-1]==s[i])
            {
                flag = false;
                ans.pop_back();
            }
            if(flag)ans.push_back(s[i]);
        }
        return ans;
    }
};