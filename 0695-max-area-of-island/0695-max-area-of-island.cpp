class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size())return 0;
        if(grid[i][j]==0)return 0;
        
        grid[i][j] = 0;
        int left = solve(grid, i, j-1);
        int right = solve(grid, i,j+1);
        int up = solve(grid, i-1, j);
        int down = solve(grid, i+1, j);
        
        return 1 + left + right + up + down;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    ans = max(ans, solve(grid, i, j));
                }
            }
        }
        return ans;
    }
};