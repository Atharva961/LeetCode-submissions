class Solution {
public:
    bool equal(int a, int b, int c, int d)
    {
        return a==b && b==c && c==d && d==a;
    }
    Node * solve(vector<vector<int>>& grid, int i, int j, int len)
    {
        Node * n = new Node();
        if(len==1)
        {
            n->isLeaf = true;
            n->val = grid[i][j];
            n->topLeft = NULL;
            n->topRight = NULL;
            n->bottomLeft = NULL;
            n->bottomRight = NULL;
        }
        else
        {
            n->val = grid[i][j];
            n->topLeft = solve(grid, i, j, len/2);
            n->topRight = solve(grid, i, j+len/2, len/2);
            n->bottomLeft = solve(grid, i+len/2, j, len/2);
            n->bottomRight = solve(grid, i+len/2, j+len/2, len/2);
            n->isLeaf = false;
            if(n->topLeft->isLeaf && n->topRight->isLeaf && n->bottomLeft->isLeaf && n->bottomRight->isLeaf)
            {
                if(equal(n->topLeft->val, n->topRight->val, n->bottomLeft->val, n->bottomRight->val))
                {
                    n->isLeaf = true;
                    n->topLeft = NULL;
                    n->topRight = NULL;
                    n->bottomLeft = NULL;
                    n->bottomRight = NULL;
                }
            }
        }
        return n;
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};