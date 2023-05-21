class Solution {
public:
    bool check(string& s, int index, int temp_sum, int sum, int n)
    {
        if(index>=s.size() && temp_sum + sum == n)return true;
        if(index>=s.size() && temp_sum + sum != n)return false;
        if(sum > n)return false;
        
        bool split = check(s, index+1, 0, sum+(temp_sum*10 + (s[index]-'0')), n);
        bool dont_split = check(s, index+1, temp_sum*10 + (s[index]-'0'), sum, n);
        
        return split||dont_split;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            string s = to_string(i*i);
            if(check(s, 0, 0, 0, i))ans+=(i*i);
        }
        
        return ans;
    }
};