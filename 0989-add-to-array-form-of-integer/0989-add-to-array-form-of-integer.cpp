class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        string s = to_string(k);
        
        int i = num.size()-1, j = s.size()-1;
        int carry = 0;
        while(i>=0 || j>=0)
        {
            int sum = carry;
            if(i>=0)sum+=num[i--];
            if(j>=0)sum+=(s[j--]-'0');
            ans.push_back(sum%10);
            carry = sum/10;
        }
        if(carry!=0)ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};