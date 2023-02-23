class Solution {
public:
    bool square(vector<vector<int>>& v, int i1, int j1, int w)
    {
        for(int i=i1; i<i1+w; i++)
        {
            for(int j=j1; j<j1+w; j++)
            {
                if(v[i][j]==0)return false;
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int maxx = min(n, m);
        int ans = 0;
        
        for(int w=1; w<=maxx; w++)
        {
            for(int i=0; i<=n-w; i++)
            {
                for(int j=0; j<=m-w; j++)
                {
                    if(v[i][j]==1)
                    {
                        if(square(v, i, j, w))ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};