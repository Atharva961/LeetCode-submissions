class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, int> trustedBy, trusts;
        
        for(auto i:trust)
        {
            trusts[i[0]]++;
            trustedBy[i[1]]++;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(trustedBy[i]==n-1 && trusts[i]==0)return i;
        }
        return -1;
    }
};