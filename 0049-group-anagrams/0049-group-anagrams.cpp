class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for(string s:strs)
        {
            vector<int> h(26, 0);
            for(char i:s)h[i-'a']++;
            m[h].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto i:m)ans.push_back(i.second);
        return ans;
    }
};