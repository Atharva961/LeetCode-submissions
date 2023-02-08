class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows==1)return s;
        int level = 0;
        bool pos = true;
        vector<string> levels(numRows, "");
        
        for(int i=0; i<s.size(); i++)
        {
            levels[level]+=s[i];
            if(level==numRows-1)pos = false;
            if(level==0)pos = true;
            if(pos)level++;
            else level--;
        }
        string ans;
        for(int i=0; i<levels.size(); i++)
        {
            ans+=levels[i];
        }
        return ans;
    }
};