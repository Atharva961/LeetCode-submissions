class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> v(26);
        for(string i:ideas)v[i[0]-'a'].insert(i.substr(1));
        long long pairs = 0;
        for(int i=0; i<26; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                unordered_set<string> s;
                s.insert(v[i].begin(), v[i].end());
                s.insert(v[j].begin(), v[j].end());
                pairs+=(v[i].size()-s.size())*(v[j].size()-s.size());
            }
        }
        return pairs*2;
    }
};