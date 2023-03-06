class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                int count = 0;
                count+=1;
                for(int j=i+1; j<s.size(); j++)
                {
                    if(s[j]==')' && count==0)break;
                    else if(s[j]==')')
                    {
                        count--;
                        if(count==0)ans = max(ans, j-i+1);
                    }
                    else if(s[j]=='(')
                    {
                        count+=1;
                    }
                }
            }
        }
        return ans;
    }
};