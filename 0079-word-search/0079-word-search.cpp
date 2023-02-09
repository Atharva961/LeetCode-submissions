class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int i, int j)
    {
        if(word.size()==0)return true;
        if(i<0 || i==board.size() || j<0 || j==board[0].size())return false;
        if(board[i][j]=='*' || board[i][j]!=word[0])return false;
        
        char c = board[i][j];
        board[i][j] = '*';
        string pass = word.substr(1);
        bool left = solve(board, pass, i, j-1);
        bool right = solve(board, pass, i, j+1);
        bool up = solve(board, pass, i-1, j);
        bool down = solve(board, pass, i+1, j);
        board[i][j] = c;
        
        return left||right||up||down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    ans|=solve(board, word, i, j);
                }
            }
        }
        return ans;
    }
};