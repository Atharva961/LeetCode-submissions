class Solution {
public:
    int sum(int n)
    {
        int ans = 0;
        for(int i=1; i<=n; i++)ans+=i;
        return ans;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> m;
        for(int i:time)m[i%60]++;
        
        int pairs = 0;
        for(int i=0; i<=30; i++)
        {
            if(i==0 || i==30)pairs+=sum(m[i]-1);
            else pairs+=(m[i]*m[60-i]);
            // cout<<i<<"->"<<pairs<<endl;
        }
        return pairs;
    }
};