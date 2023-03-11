bool isPalindrome(string s, int beg, int end)
{
    while(beg<=end)
    {
        if(s[beg]!=s[end])
        {
            return false;
        }
        beg++;
        end--;
    }
    return true;
}
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int beg = 0, end = n-1;
        bool ans = true;
        while(beg<=end)
        {
            if(s[beg]!=s[end])
            {
                return isPalindrome(s, beg+1, end)||isPalindrome(s, beg, end-1);
            }
            else
            {
                beg++;
                end--;
            }
        }
        return ans;
    }
};