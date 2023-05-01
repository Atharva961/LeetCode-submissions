class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;
        double maxx = 0, minn = INT_MAX, sum = 0;
        for(int i:salary)
        {
            if(i>maxx)maxx = i;
            if(i<minn)minn = i;
            sum+=i;
        }
        sum-=maxx;
        sum-=minn;
        ans = sum/(salary.size()-2);
        return ans;
    }
};