class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
                // cout<<sum[i][j]<<" ";
            }
            // cout<<endl;
        }
        this->sum = sum;
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        // printf("(%d, %d, %d, %d)\n", r1, c1, r2, c2);
        int ans = sum[r1][c1] + sum[r2+1][c2+1] - sum[r1][c2+1] - sum[r2+1][c1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */