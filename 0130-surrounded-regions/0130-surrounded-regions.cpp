class Solution {
public:
    vector<pair<int, int>> solve(vector<vector<int>>& v, int i0, int j0, int id)
    {
        vector<pair<int,int>> ans;
        ans.push_back(make_pair(i0, j0));
        v[i0][j0] = id;
        queue<pair<int,int>> q;
        q.push(make_pair(i0, j0));
        while(!q.empty())
        {
            pair<int, int> f = q.front();
            q.pop();
            int i = f.first, j = f.second;
            if(i-1>=0 && v[i-1][j]==0)
            {
                v[i-1][j] = id;
                q.push(make_pair(i-1, j));
                ans.push_back(make_pair(i-1, j));
            }
            if(i+1<v.size() && v[i+1][j]==0)
            {
                v[i+1][j] = id;
                q.push(make_pair(i+1, j));
                ans.push_back(make_pair(i+1, j));
            }
            if(j+1<v[0].size() && v[i][j+1]==0)
            {
                v[i][j+1] = id;
                q.push(make_pair(i, j+1));
                ans.push_back(make_pair(i, j+1));
            }
            if(j-1>=0 && v[i][j-1]==0)
            {
                v[i][j-1] = id;
                q.push(make_pair(i, j-1));
                ans.push_back(make_pair(i, j-1));
            }
        }

        return ans;
    }
    bool check(vector<vector<int>>& v,pair<int, int> p, int id)
    {
        int i = p.first;
        int j = p.second;
        if(i-1<0)return false;
        if(v[i-1][j]!=id && v[i-1][j]!=-1)return false;
        if(j-1<0)return false;
        if(v[i][j-1]!=id && v[i][j-1]!=-1)return false;
        if(i+1>=v.size())return false;
        if(v[i+1][j]!=id && v[i+1][j]!=-1)return false;
        if(j+1>=v[0].size())return false;
        if(v[i][j+1]!=id && v[i][j+1]!=-1)return false;
        
        return true;
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> v;
        for(int i=0; i<board.size(); i++)
        {
            vector<int> temp;
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]=='X')
                {
                    temp.push_back(-1);
                }
                else temp.push_back(0);
            }
            v.push_back(temp);
        }

        int id = 1;
        vector<vector<pair<int, int>>> islands;
        islands.push_back({make_pair(-1, -1)});

        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].size(); j++)
            {
                if(v[i][j]==0)
                {
                    vector<pair<int, int>> temp = solve(v, i, j, id);
                    id++;
                    islands.push_back(temp);
                }
            }
        }

        unordered_map<int, int> m;
        m[-1] = 1;
        
        for(int i=1; i<islands.size(); i++)
        {
            bool flag = true;
            for(auto j:islands[i])
            {
                if(!check(v, j, i))
                {
                    flag = false;
                    break;
                }
            }
            m[i] = flag;
        }
        
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].size(); j++)
            {
                v[i][j] = m[v[i][j]];
            }
        }
        
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].size(); j++)
            {
                if(v[i][j]==1)
                {
                    board[i][j]='X';
                }
                else board[i][j]='O';
            }
        }
        
    }
};