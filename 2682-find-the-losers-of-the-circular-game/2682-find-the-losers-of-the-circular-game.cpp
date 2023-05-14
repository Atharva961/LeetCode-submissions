class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> h(n, 0);
        int start = 0;
        h[0] = 1;
        for(int i=1; ;i++)
        {
            start = (start + i*k)%(n);
            if(h[start])break;
            h[start] = 1;
        }
        vector<int> ans;
        for(int i=0; i<h.size(); i++)if(!h[i])ans.push_back(i+1);
        return ans;
    }
};