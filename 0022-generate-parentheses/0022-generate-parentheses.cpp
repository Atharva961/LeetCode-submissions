class Solution {
public:
    set<string> s;
    void solve(string& temp, int opened, int closed, int n)
    {
        if(opened==n && closed==n)
        {
            s.insert(temp);
            return;
        }
        if(closed<opened)
        {
            string pass = temp;
            pass.push_back(')');
            solve(pass, opened, closed+1, n);
        }
        if(opened<n)
        {
            string pass = temp;
            pass.push_back('(');
            solve(pass, opened+1, closed, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(temp, 0, 0, n);
        vector<string> ans(s.begin(), s.end());
        
        return ans;
    }
};