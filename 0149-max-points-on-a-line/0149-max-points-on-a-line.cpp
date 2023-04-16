class Solution {
public:
    double slope(vector<int>& a, vector<int>& b)
    {
        double x1 = a[0], x2 = b[0], y1 = a[1], y2 = b[1];
        
        if(y2-y1==0)return INT_MIN;
        double ans = (x2-x1)/(y2-y1);
        return ans;
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)return int(points.size());
        int ans = 0;
        for(int i=0; i<points.size(); i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                int count = 2;
                double s1 = slope(points[i], points[j]);
                for(int k=j+1; k<points.size(); k++)
                {
                    double s2 = slope(points[i], points[k]);
                    if(s1==s2)count++;
                }
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};