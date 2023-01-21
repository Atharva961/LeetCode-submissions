class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        for(auto i:queries)
        {
            int r1 = i[0];
            int c1 = i[1];
            int r2 = i[2];
            int c2 = i[3];
            
            ans[r1][c1]+=1;
            if(r2+1<n && c2+1<n)ans[r2+1][c2+1]+=1;
            if(r2+1<n)ans[r2+1][c1]-=1;
            if(c2+1<n)ans[r1][c2+1]-=1;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                ans[i][j] += ans[i][j-1];
            }
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans[i][j] += ans[i-1][j];
            }
        }
        
        return ans;
    }
};