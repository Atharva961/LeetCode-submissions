class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        for(int i=0; i<path.size(); i++)
        {
            if(path[i]=='/')continue;
            string temp = "";
            while(i<path.size() && path[i]!='/')
            {
                temp+=path[i];
                i++;
            }
            if(temp==".")continue;
            else if(temp=="..")
            {
                if(st.size())st.pop_back();
            }
            else st.push_back(temp);
        }
        
        string ans = "";
        for(string i:st)
        {
            ans.push_back('/');
            ans+=i;
        }
        return ans.size()==0?"/":ans;
    }
};