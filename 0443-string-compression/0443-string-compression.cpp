class Solution {
public:
    int compress(vector<char>& chars) {
        char curr = ' ';
        int count = 0, ans = 0;
        int ptr = 0;
        
        for(int i=0; i<chars.size(); i++)
        {
            if(chars[i]!=curr)
            {
                if(curr!=' '){ans+=1;
                if(count>1)
                {
                    ans+=(to_string(count).length());
                }
                chars[ptr] = curr;
                ptr++;
                if(count>=2)
                {
                    string s = to_string(count);
                    for(int i=0; i<s.size(); i++)
                    {
                        chars[ptr] = s[i];
                        ptr++;
                    }   
                }}
                curr = chars[i];
                count = 1;
            }
            else count++;
        }
        
        chars[ptr] = curr;
        ptr++;
        if(count==1)
        {
            ans+=1;
        }
        if(count>1)
        {
            ans+=(1+to_string(count).length());
            string s = to_string(count);
            for(int i=0; i<s.size(); i++)
            {
                chars[ptr] = s[i];
                ptr++;
            } 
        }
        
        return ans;
    }
};