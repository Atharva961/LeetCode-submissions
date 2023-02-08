class Solution {
public:
    vector<int> ans;
    void solve(vector<vector<int>>& matrix, int deg)
    {
        // cout<<deg<<endl;
        int r1 = 0, c1 = 0;
        int r2 = matrix.size()-1, c2 = matrix[0].size()-1;
        
        r1+=deg;
        c1+=deg;
        r2-=deg;
        c2-=deg;
        
        // cout<<"("<<r1<<","<<c1<<")"<<endl;
        // cout<<"("<<r2<<","<<c2<<")"<<endl;
        
         if(ans.size()==matrix.size()*matrix[0].size())return;
        for(int i=c1; i<=c2; i++)ans.push_back(matrix[r1][i]);
        if(ans.size()==matrix.size()*matrix[0].size())return;
        for(int i=r1+1; i<=r2; i++)ans.push_back(matrix[i][c2]);
        if(ans.size()==matrix.size()*matrix[0].size())return;
        for(int i=c2-1; i>=c1; i--)ans.push_back(matrix[r2][i]);
        if(ans.size()==matrix.size()*matrix[0].size())return;
        for(int i=r2-1; i>r1; i--)
        {
            ans.push_back(matrix[i][c1]);
            if(ans.size()==matrix.size()*matrix[0].size())break;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r  = matrix.size(), c = matrix[0].size();
        int max_deg = min(r/2, c/2);
        
        for(int i=0; i<=max_deg; i++)solve(matrix, i);
        return ans;
    }
};