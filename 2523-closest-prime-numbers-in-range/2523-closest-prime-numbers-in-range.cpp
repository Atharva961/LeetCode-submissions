class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = {};
        vector<bool> sieve(right+1, false);
        
        for(long long i=2; i<sieve.size(); i++)
        {
            if(!sieve[i])
            {
                primes.push_back(i);
                for(long long j=i*i; j<sieve.size(); j+=i)sieve[j] = true;
            }
        }
        
        int idx = lower_bound(primes.begin(), primes.end(), left)-primes.begin();
        
        if(primes.size()-idx<=1)return {-1, -1};
        
        int min_diff = INT_MAX;
        int min_ind = -1;
        
        for(int i=idx+1; i<primes.size(); i++)
        {
            if(primes[i]-primes[i-1]<min_diff)
            {
                min_diff = primes[i]-primes[i-1];
                min_ind = i;
            }
        }
        
        return {primes[min_ind-1], primes[min_ind]};
    }
};