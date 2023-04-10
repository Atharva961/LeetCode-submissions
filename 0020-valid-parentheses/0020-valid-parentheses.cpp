class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(auto i:s)
        {
            if(i=='(' || i=='[' || i=='{')st.push_back(i);
            else
            {
                if(st.size()==0)return false;
                if(i==')')
                {
                    if(st[st.size()-1]!='(')return false;
                }
                if(i==']')
                {
                    if(st[st.size()-1]!='[')return false;
                }
                if(i=='}')
                {
                    if(st[st.size()-1]!='{')return false;
                }
                st.pop_back();
            }
        }
        return st.size()==0;
    }
};