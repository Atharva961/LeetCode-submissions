
class Solution {
public:
    void print(vector<int>& v)
    {
        for(int i:v)cout<<i<<" ";
        cout<<endl;
    }
    int calculate(string s) {
        vector<int> st;
        int num = 0;
        char sign = '+';
        s.push_back(' ');
        for(int i=0; i<s.size(); i++)
        {
            
            if(isdigit(s[i]))
            {
                num = num*10 + (s[i]-'0');
            }
            else if(!isspace(s[i]) || i==s.size()-1)
            {
                if(sign=='+')
                {
                    st.push_back(num);
                }
                if(sign=='-')
                {
                    st.push_back(-num);
                }
                else 
                {
                    if(sign == '*')
                    {
                        int t = st[st.size()-1];
                        st.pop_back();
                        st.push_back(t*num);
                    }
                    else if(sign=='/')
                    {
                        int t = st[st.size()-1];
                        st.pop_back();
                        st.push_back(t/num);
                    }
                }
                num = 0;
                sign = s[i];
            }
            // print(st);
        }
        
        int ans = 0;
        for(int i:st)ans+=i;
        return ans;
        
    }
};