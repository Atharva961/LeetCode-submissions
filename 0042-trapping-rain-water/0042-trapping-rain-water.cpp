class Solution {
public:
    int trap(vector<int>& v) {
        int beg = 0, end = v.size()-1;
        int ans = 0;
        int mleft = 0, mright = 0;
        while(beg<=end)
        {
            if(v[beg]<=v[end])
            {
                mleft = max(mleft, v[beg]);
                ans+=(mleft-v[beg]);
                beg++;
            }
            else
            {
                mright = max(mright, v[end]);
                ans+=(mright-v[end]);
                end--;
            }
        }
        
        return ans;
    }
};