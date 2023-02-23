class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int ans = 0;
        
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[0].size(); j++)
            {
                if(i>0 && j>0 && v[i][j]>0)v[i][j]+=min(v[i-1][j-1], min(v[i-1][j], v[i][j-1]));
                ans+=v[i][j];
            }
        }
        
        return ans;
    }
};