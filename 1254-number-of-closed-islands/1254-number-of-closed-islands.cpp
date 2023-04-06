class Solution {
public:
    void solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size())return;
        if(grid[i][j]==1)return;
        grid[i][j] = 1;
        solve(grid, i+1, j);
        solve(grid, i-1, j);
        solve(grid, i, j+1);
        solve(grid, i, j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++)
        {
            if(grid[i][0]==0)solve(grid, i, 0);
            if(grid[i][grid[0].size()-1]==0)solve(grid, i, int(grid[0].size()-1));
        }
        for(int i=0; i<grid[0].size(); i++)
        {
            if(grid[0][i]==0)solve(grid, 0, i);
            if(grid[grid.size()-1][i]==0)solve(grid, int(grid.size()-1), i);
        }
        
        int ans = 0;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    solve(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};