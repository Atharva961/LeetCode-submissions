class Solution {
public:
    int maxArea(vector<int>& height) {
        int beg = 0, end = height.size()-1;
        int ans = 0;
        while(beg<end)
        {
            int vol = (end-beg)*(min(height[beg], height[end]));
            ans = max(ans, vol);
            if(height[beg]<height[end])
            {
                beg++;
            }
            else end--;
        }
        return ans;
    }
};