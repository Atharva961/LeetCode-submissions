class Solution {
public:
    int solve(vector<vector<char>>& mat, int i, int j, vector<vector<int>>& dp, int& maxx)
    {
        if(i>=mat.size() || j>=mat[0].size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right = solve(mat, i, j+1, dp, maxx);
        int diagonal = solve(mat, i+1, j+1, dp, maxx);
        int down = solve(mat, i+1, j, dp, maxx);
        
        if(mat[i][j]=='1')
        {
            maxx = max(maxx, 1 + min(right, min(diagonal, down)));
            return dp[i][j] = 1 + min(right, min(diagonal, down));
        }
        return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        int temp = solve(matrix, 0, 0, dp, ans);
        
        return ans*ans;
    }
};