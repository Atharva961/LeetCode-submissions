class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int beg = 0, end = s.size()-1;
        while(beg<=end)
        {
            if(s[beg]!=s[end])return false;
            beg++;
            end--;
        }
        return true;
    }
};