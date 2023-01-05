class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        
        int arrow = INT_MIN;
        int ans = 0;
        
        for(int i=0; i<points.size(); i++)
        {
            if(arrow<points[i][0] || points[i][0]==INT_MIN)
            {
                ans++;
                arrow = points[i][1];
            }
        }
        
        return ans;
    }
};