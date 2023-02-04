class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26, 0);
        for(int i=0; i<s1.size(); i++)
        {
            c1[s1[i]-'a']+=1;
        }
        int l = 0, r = s1.size()-1;
        int n = s2.size();
        while(r<n)
        {
            vector<int> c2(26, 0);
            for(int i=l; i<=r; i++)
            {
                c2[s2[i]-'a']+=1;
            }
            if(c1==c2)return true;
            l++;
            r++;
        }
        return false;
    }
};