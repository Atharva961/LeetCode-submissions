class Solution {
public:
    int trap(vector<int>& v) {
        int beg = 0, end = v.size()-1;
        int ans = 0;
        int mbeg = 0, mend = 0;
        
        while(beg<=end)
        {
            if(v[beg]<=v[end])
            {
                mbeg = max(v[beg], mbeg);
                ans+=(mbeg-v[beg]);
                beg++;
            }
            else
            {
                mend = max(v[end], mend);
                ans+=(mend-v[end]);
                end--;
            }
        }
        
        return ans;
    }
};