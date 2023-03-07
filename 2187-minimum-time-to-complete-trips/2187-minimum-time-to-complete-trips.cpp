class Solution {
public:
    long long trips(vector<int>& v, long long time)
    {
        long long int ans = 0;
        for(auto x : v)
        {
            long long int val = x;
            ans += (time / val);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long beg = 1, end = 1e14;
        while(beg<end)
        {
            long long mid = beg + (end-beg)/2;
            if(trips(time, mid)>=totalTrips)
            {
                end = mid;
            }
            else beg = mid+1;
        }
        return beg;
    }
};