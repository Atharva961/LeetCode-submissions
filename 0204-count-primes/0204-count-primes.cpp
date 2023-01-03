class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> sieve(n+1, true);
        sieve[0] = false;
        sieve[1] = false;
        
        for(int i=2; i*i<=n; i++)
        {
            if(sieve[i])
            {
                for(int j=i*i; j<=n; j+=i)sieve[j] = false;
            }
        }
        
        int ans = 0;
        
        for(int i=2; i<n; i++)if(sieve[i])ans++;
        
        return ans;
    }
};