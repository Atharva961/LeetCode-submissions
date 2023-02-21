//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int beg = 0, end = n-1;
        long long ans = 0;
        int mbeg = 0, mend = 0;
        
        while(beg<=end)
        {
            if(arr[beg]<=arr[end])
            {
                mbeg = max(mbeg, arr[beg]);
                ans+=(mbeg-arr[beg]);
                beg++;
            }
            else
            {
                mend = max(mend, arr[end]);
                ans+=(mend-arr[end]);
                end--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends