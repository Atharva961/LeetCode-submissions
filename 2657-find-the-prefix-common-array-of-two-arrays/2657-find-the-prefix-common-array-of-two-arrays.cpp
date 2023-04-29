class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i=0; i<A.size(); i++)
        {
            m[A[i]]++;
            if(m[A[i]]==2)count++;
            m[B[i]]++;
            if(m[B[i]]==2)count++;
            ans.push_back(count);
        }
        return ans;
    }
};