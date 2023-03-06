class Solution {
public:
    int solve(vector<int>& heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        for(char i:matrix[0])v.push_back(i-'0');
        int ans = solve(v);
        for(int i=1; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]=='1')
                {
                    v[j]+=1;
                }
                else v[j] = 0;
            }
            ans = max(ans, solve(v));
        }
        return ans;
    }
};