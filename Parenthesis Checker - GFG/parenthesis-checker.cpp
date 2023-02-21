//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        string st = "";
        for(auto i:x)
        {
            if(i=='(' || i=='{' || i=='[')
            {
                st.push_back(i);
            }
            if(i==')')
            {
                char b = st.back();
                st.pop_back();
                if(b!='(')return false;
            }
            if(i=='}')
            {
                char b = st.back();
                st.pop_back();
                if(b!='{')return false;
            }
            if(i==']')
            {
                char b = st.back();
                st.pop_back();
                if(b!='[')return false;
            }
        }
        if(st.size()==0)return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends