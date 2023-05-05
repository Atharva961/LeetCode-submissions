class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int beg = 0, end = k-1;
        int count = 0;
        for(int i=beg; i<=end; i++)if(isVowel(s[i]))count++;
        int ans = count;
        while(end<s.size())
        {
            if(isVowel(s[beg]))count--;
            beg++;
            end++;
            if(isVowel(s[end]))count++;
            ans = max(ans, count);
        }
        return ans;
    }
};