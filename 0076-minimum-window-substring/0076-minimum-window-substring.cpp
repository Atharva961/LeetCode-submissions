class Solution {
public:
    bool compare(map<char, int>& m1, map<char, int>& m2)
    {
        string s = "abcdefghijklmnopqrstuvwxyz";
        string l = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        for(auto i:s)
        {
            if(m1[i]<m2[i])return false;
        }
        for(auto i:l)
        {
            if(m1[i]<m2[i])return false;
        }
        
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        if(t.size()==1)
        {
            for(auto i:s)if(i==t[0])return t;
            return "";
        }
        if(s.size()==t.size())
        {
            map<char, int> m1, m2;
            for(int i=0; i<s.size(); i++)
            {
                m1[s[i]]++;
                m2[t[i]]++;
            }
            if(m1==m2)return s;
            return "";
        }
        
        map<char, int> m1, m2;
        for(auto i:t)m2[i]++;
        int beg = 0, end = 0;
        
        pair<int, int> p = make_pair(-1, s.size());
        
        while(end<s.size())
        {
            m1[s[end]]++;
            while(compare(m1, m2) && beg<end)
            {
                if(end-beg<p.second-p.first)
                {
                    p = make_pair(beg, end);
                }
                m1[s[beg]]--;
                beg++;
            }
            end++;
            // cout<<p.first<<","<<p.second<<endl;
        }
        
        string ans = "";
        if(p.first==-1)return "";
        for(int i=p.first; i<=p.second; i++)ans+=s[i];
        
        return ans;
    }
};