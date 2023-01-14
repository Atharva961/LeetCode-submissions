class Solution {
public:
    void solve(map<char, set<int>>& m, char c, char& ans, vector<bool>& visited)
    {
        if(visited[c-'a'])return;
        visited[c-'a'] = true;
        ans = min(ans, c);
        
        for(char i:m[c])
        {
            ans = min(ans, i);
            solve(m, i, ans, visited);
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char, set<int>> m;
        
        for(int i=0; i<s1.size(); i++)
        {
            m[s1[i]].insert(s2[i]);
            m[s2[i]].insert(s1[i]);
        }
        
        string ans = "";
        
        for(int i=0; i<baseStr.size(); i++)
        {
            char temp = 'z'+1;
            vector<bool> visited(26, false);
            solve(m, baseStr[i], temp, visited);
            ans.push_back(temp);
        }
        
        return ans;
    }
};