class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> v;
        for(int i=0; i<capital.size(); i++)v.push_back({capital[i], profits[i]});
        sort(v.begin(), v.end());
        priority_queue<int> q;
        int i = 0;
        int ans = w;
        while(k--)
        {
            while(i<v.size() && v[i][0]<=ans)q.push(v[i++][1]);
            if(q.empty())break;
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};