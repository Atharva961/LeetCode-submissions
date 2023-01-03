class Solution {
public:
    int smallestValue(int n) {
        if(n==4)return 4;
        vector<bool> sieve(n+1, false);
        
        for(int i=2; i*i<=n; i++)
        {
            if(!sieve[i])
            {
                for(int j=i*i; j<=n; j+=i)sieve[j] = true;
            }
        }
        
        while(true)
        {
            int sum = 0;
            int d = 2;
            
            if(!sieve[n])return n;
            while(n>1)
            {
                if(n%d==0)
                {
                    sum+=d;
                    n/=d;
                }
                else d++;
            }
            n = sum;
        }
        
        return n;
    }
};