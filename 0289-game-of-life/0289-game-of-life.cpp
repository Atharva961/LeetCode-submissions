class Solution {
public:
    int value(vector<vector<int>>& board, int i, int j)
    {
        if(i<0 || i==board.size() || j<0 || j==board[0].size())return 0;
        return board[i][j];
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dup = board;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                int n = value(dup, i+1, j) + value(dup, i-1, j) + value(dup, i, j+1) + value(dup, i, j-1) + value(dup, i+1, j+1) + value(dup, i-1, j+1) + value(dup, i+1, j-1) + value(dup, i-1, j-1);
                if(n<=1)board[i][j] = 0;
                if(n==3)board[i][j] = 1;
                if(n>3)board[i][j] = 0;
            }
        }
    }
};