class Solution {
public:
    int solve(vector<int>& v, int m)
    {
        int i = 0;
        int ans = 0;
        vector<int> piles = v;
        for (int p : piles)
                ans += (p + m - 1) / m;
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int beg = 1, end = INT_MAX;
        while(beg<end)
        {
            int mid = beg + (end-beg)/2;
            int t = solve(piles, mid);
            if(t>h)
            {
                beg = mid + 1;
            }
            else end = mid;
        }
        return beg;
    }
};