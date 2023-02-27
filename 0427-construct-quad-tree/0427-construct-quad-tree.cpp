/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

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
        // printf("(%d, %d, %d, %d)\n", i, j, len, n->isLeaf);
        return n;
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};