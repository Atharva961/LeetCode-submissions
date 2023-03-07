class Solution {
public:
    int time(vector<int>& weights, int cap)
    {
        int ans = 0;
        int temp = 0;
        for(auto i:weights)
        {
            temp+=i;
            if(temp>cap)
            {
                ans++;
                temp = i;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int beg = 0, end = INT_MAX;
        for(auto i:weights)beg = max(i, beg);
        while(beg<end)
        {
            int mid = beg + (end-beg)/2;
            int t = time(weights, mid);
            if(t>=days)
            {
                beg = mid+1;
            }
            else
            {
                end = mid;
            }
        }
        return beg;
    }
};