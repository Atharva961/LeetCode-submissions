class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxx = arr[arr.size()-1];
        vector<int> h(maxx+1, 0);
        for(int i:arr)h[i]++;
        for(int i=1; i<h.size(); i++)
        {
            if(h[i]==0)k--;
            if(k==0)return i;
        }
        return maxx + k;
    }
};