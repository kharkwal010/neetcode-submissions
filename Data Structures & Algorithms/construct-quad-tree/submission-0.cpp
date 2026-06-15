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
    Node* dfs(vector<vector<int>>& grid, int r, int c, int n){
        bool same = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[r][c]!=grid[r+i][c+j]){
                    same=false;
                    break;
                }
            }
        }
        if(same) return new Node(grid[r][c], true);
        int mid = n/2;
        Node* tl = dfs(grid, r, c, n/2);
        Node* tr = dfs(grid, r, c+mid, n/2);
        Node* bl = dfs(grid, r+mid, c, n/2);
        Node* br = dfs(grid, r+mid, c+mid, n/2);
        return new Node(false, false, tl, tr, bl, br);
    }
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }
};