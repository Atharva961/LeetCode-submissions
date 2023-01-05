class Solution {
public:
    void printArray(vector<vector<int>>& a)
    {
        for(auto i:a)
        {
            cout<<i[0]<<","<<i[1]<<" ";
        }
        cout<<endl;
    }
    static bool compare(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int pos = intervals[0][1];
        int ans = 0;
        
        for(int i=1; i<intervals.size(); i++)
        {
            bool del = false;
            if(pos>intervals[i][0])
            {
                ans++;
                del = true;
            }
            if(!del)pos = max(pos, intervals[i][1]);
        }
        
        return ans;
    }
};