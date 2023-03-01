class Solution {
public:
    vector<string> dict;
    set<vector<int>> parts;
    void solve(string& s, int prev, int index, vector<int>& p)
    {
        // cout<< s.substr(prev, index-prev)<<","<<binary_search(dict.begin(), dict.end(), s.substr(prev, index-prev))<<endl;
        if(index==s.size())
        {
            if(binary_search(dict.begin(), dict.end(), s.substr(prev, index-prev)))
            {
                parts.insert(p);
            }
            return;
        }
        vector<int> exc = p;
        if(binary_search(dict.begin(), dict.end(), s.substr(prev, index-prev)))
        {
            p.push_back(index);
            solve(s, index, index+1, p);
        }
        solve(s, prev, index+1, exc);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->dict = wordDict;
        sort(dict.begin(), dict.end());
        vector<int> p;
        solve(s, 0, 0, p);
        vector<string> ans;
        for(vector<int> v:parts)
        {
            string temp = s;
            int add = 0;
            for(int i:v)
            {
                // cout<<i<<" ";
                temp.insert(i + add, " ");
                add++;
            }
            // cout<<endl;
            ans.push_back(temp);
        }
        
        return ans;
    }
};