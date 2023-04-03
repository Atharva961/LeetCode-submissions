class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        sort(v.begin(), v.end());
        int beg = 0, end = v.size()-1;
        int ans = 0;
        while(beg<=end)
        {
            if(beg==end)
            {
                ans++;
                break;
            }
            if(v[beg]+v[end]<=limit)
            {
                beg++;
                end--;
            }
            else if(v[beg]+v[end]>limit)
            {
                end--;
            }
            ans++;
        }
        return ans;
    }
};