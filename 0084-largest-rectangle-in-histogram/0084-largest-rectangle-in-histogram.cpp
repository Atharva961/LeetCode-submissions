class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int ans = 0;
        
        for(int i=0; i<heights.size(); i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                int h = heights[s.top()];
                s.pop();
                int w;
                if(s.empty())
                {
                    w = -1;
                }
                else w = s.top();
                int area = h * (i-w-1);
                ans = max(ans, area);
            }
            s.push(i);
        }
        
        return ans;
    }
};