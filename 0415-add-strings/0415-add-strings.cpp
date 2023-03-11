class Solution {
public:
    string solve(string& s, string& l)
    {
        if(s.size()==0)return l;
        int i = s.size()-1, j = l.size()-1;
        int sum = 0, carry = 0;
        string ans = "";
        while(i>=0)
        {
            int a = s[i]-'0';
            int b = l[j]-'0';
            sum = a+b+carry;
            carry = sum/10;
            ans+=to_string(sum%10);
            i--;
            j--;
        }
        while(j>=0)
        {
            int b = l[j]-'0';
            sum = b+carry;
            carry = sum/10;
            ans+=to_string(sum%10);
            j--;
        }
        if(carry)ans+=to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addStrings(string num1, string num2) {
        string ans = "";
        if(num1.size()>num2.size())ans = solve(num2, num1);
        else ans = solve(num1, num2);
        
        return ans;
    }
};