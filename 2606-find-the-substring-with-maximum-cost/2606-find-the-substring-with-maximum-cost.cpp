class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26, 0);
        for(int i=0; i<v.size(); i++)v[i] = i+1;
        for(int i=0; i<chars.size(); i++)
        {
            v[chars[i]-'a'] = vals[i];
        }
        int ans = 0, sum = 0;
        for(int i=0; i<s.size(); i++)
        {
            sum = max(v[s[i]-'a'], sum+v[s[i]-'a']);
            ans = max(ans, sum);
        }
        return ans;
    }
};