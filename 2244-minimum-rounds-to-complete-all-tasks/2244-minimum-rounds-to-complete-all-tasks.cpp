class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        for(auto i:tasks)m[i]++;
        
        vector<int> v;
        for(auto i:m)v.push_back(i.second);
        sort(v.begin(), v.end());
        
        int ans = 0;
        for(int i=v.size()-1; i>=0; )
        {
            if(v[i]==0)i--;
            else if(v[i]==1)return -1;
            else if(v[i]==2 || v[i]==3)
            {
                ans++;
                i--;
            }
            else if(v[i]==4)
            {
                ans+=2;
                i--;
            }
            else
            {
                ans++;
                v[i]-=3;
            }
        }
        
        return ans;        
    }
};