class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int len = v.size()-k;
        int sum = 0, min_sum = INT_MAX, total_sum = 0;
        for(int i:v)total_sum+=i;
        for(int i=0; i<len; i++)sum+=v[i];
        min_sum = min(sum, min_sum);
        
        int end = len-1, beg = 0;
        while(end<v.size()-1)
        {
            sum-=v[beg];
            beg++;
            end++;
            sum+=v[end];
            min_sum = min(sum, min_sum);
        }
        return total_sum-min_sum;
    }
};