class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)return 1;
        int beg = 0, end = 0;
        int ans = 0;
        map<char, int> m;
        while(end<s.size())
        {
            m[s[end]]++;
            while(m[s[end]]>=2 && beg<end)
            {
                m[s[beg]]--;
                beg++;
            }
            ans = max(ans, end-beg+1);
            end++;
        }
        
        return ans;
    }
};