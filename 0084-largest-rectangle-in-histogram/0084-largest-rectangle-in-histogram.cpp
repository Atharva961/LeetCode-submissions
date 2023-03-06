class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==1)return heights[0];
        vector<int> prev, next;
        stack<int> s;
        s.push(0);
        for(int i=0; i<heights.size(); i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            if(s.empty())prev.push_back(-1);
            else prev.push_back(s.top());
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=heights.size()-1; i>=0; i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            if(s.empty())next.push_back(heights.size());
            else next.push_back(s.top());
            s.push(i);
        }
        
        reverse(next.begin(), next.end());
        int ans = 0;
        
        for(int i=0; i<heights.size(); i++)
        {
            int width = next[i] - prev[i] - 1;
            ans = max(ans, width * heights[i]);
        }
        
        return ans;
    }
};