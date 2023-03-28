class Solution {
public:
    long double slope(vector<int>& a, vector<int>& b)
    {
        long double x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1];
        long double result = (x2-x1)/(y2-y1);
        return result;
    }
    int minimumLines(vector<vector<int>>& v) {
        if(v.size()==1)return 0;
        int ans = 1;
        sort(v.begin(), v.end());
        
        for(int i=1; i<v.size()-1; i++)
        {
            long double s1 = slope(v[i-1], v[i]);
            long double s2 = slope(v[i], v[i+1]);
            if(s1!=s2)ans++;
        }
        return ans;
    }
};