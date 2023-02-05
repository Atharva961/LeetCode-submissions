class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> count(26, 0);
        int len = p.size();
        for(int i=0; i<len; i++)
        {
            count[p[i]-97]+=1;
        }
        int n = s.size();
        for(int i=0; i<n-len+1; i++)
        {
            vector<int> temp(26,0);
            for(int j = i; j<len+i; j++)
            {
                temp[s[j]-97]+=1;
            }
            if(temp==count)ans.push_back(i);
        }
        return ans;
    }
};