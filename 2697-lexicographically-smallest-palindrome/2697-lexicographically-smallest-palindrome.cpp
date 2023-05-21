class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int beg = 0, end = s.size()-1;
        while(beg<=end)
        {
            if(s[beg]!=s[end])
            {
                if(s[beg]>s[end])s[beg] = s[end];
                else s[end] = s[beg];
            }
            beg++;
            end--;
        }
        return s;
    }
};