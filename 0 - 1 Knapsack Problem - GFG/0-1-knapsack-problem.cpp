//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // vector<vector<int>> dp;
    // //Function to return max value that can be put in knapsack of capacity W.
    // int solve(int wt[], int val[], int index, int cap)
    // {
    //     if(cap==0)return 1;
    //     if(index==0)return 0;
    //     if(dp[index][cap]!=-1)return dp[index][cap];
    //     int ignore = solve(wt, val, index-1, cap);
    //     int include = 0;
    //     if(cap-wt[index-1]>=0)
    //     {
    //         include = val[index-1] + solve(wt, val, index-1, cap-wt[index-1]);
    //     }
    //     return dp[index][cap] = max(include, ignore);
    // }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1];
       for(int i=0; i<=W; i++)dp[0][i] = 0;
       for(int i=0; i<=n; i++)dp[i][0] = 0;
       
       for(int i=1; i<=n; i++)
       {
           for(int j=1; j<=W; j++)
           {
               int exclude = dp[i-1][j];
               int include = 0;
               if(j-wt[i-1]>=0)include = val[i-1] + dp[i-1][j-wt[i-1]];
               dp[i][j] = max(include, exclude);
           }
       }
       
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends