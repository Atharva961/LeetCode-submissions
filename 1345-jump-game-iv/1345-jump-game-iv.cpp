class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1)return 0;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++)m[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        int ans = 0;
        vector<int> visited(arr.size()+1, 0);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                if(curr==n-1)return ans;
                if(curr+1<n && !visited[curr+1])
                {
                    q.push(curr+1);
                    visited[curr+1] = true;
                }
                if(curr-1>=0 && !visited[curr-1])
                {
                    q.push(curr-1);
                    visited[curr-1] = true;
                }
                for(int i:m[arr[curr]])
                {
                    if(!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
                m[arr[curr]].clear();
            }
            ans++;
        }
        
        return -1;
    }
};