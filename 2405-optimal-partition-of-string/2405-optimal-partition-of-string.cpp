class Solution {
public:
   
    int partitionString(string s) {
        int ans = 0;
        
        vector<int> h(26, 0);
        
        for(int i=0; i<s.size(); i++)
        {
            h[s[i]-'a']+=1;
            if(h[s[i]-'a']==2)
            {
                ans++;
                h = vector<int>(26, 0);
                h[s[i]-'a'] = 1;
            }
            
        }
        
        return ans+1;
    }
};