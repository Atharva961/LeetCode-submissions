class Solution {
public:
    int minimumPartition(string s, int k) {
        long long n = 0; 
        int ans = 1;
        
        for(int i=0; i<s.size(); i++)
        {
            n = n*10 + (s[i]-'0');
            if(n>k)
            {
                ans++;
                n = s[i]-'0';
            }
            if(n>k)
            {
                return -1;
            }
        }
        
        return ans;
    }
};