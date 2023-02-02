class Solution {
public:
    bool verify(string a, string b, map<char, int> m)
    {
        int ptr1 = 0, ptr2 = 0;
        while(ptr1<a.size() && ptr2<b.size())
        {
            if(m[a[ptr1]]>m[b[ptr2]])return false;
            if(m[a[ptr1]]<m[b[ptr2]])return true;
            ptr1++;
            ptr2++;
        }
        return a.size()<=b.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        
        for(int i=0; i<order.size(); i++)m[order[i]] = i;
        
    
        for(int i=1; i<words.size(); i++)
        {
            if(!verify(words[i-1], words[i], m))return false;
        }
        
        return true;
    }
};