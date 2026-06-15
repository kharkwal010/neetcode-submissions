class Solution {
public:
    vector<vector<int>> directions= {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>> board, int r, int c, int rows, int columns, set<pair<int, int>>& visited){
        if (r<0|| c<0 || r>=rows || c>= columns || visited.find({r,c})!=visited.end() || board[r][c]!='O'){
            return;
        }
        visited.insert({r,c});
        for (int i=0; i<4; i++){
            dfs(board, r+directions[i][0], c+directions[i][1], rows, columns, visited);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        set<pair<int, int>> visited;
        for (int i=0; i<rows; i++){
            dfs(board, i, 0, rows, columns, visited);
            dfs(board, i, columns-1, rows, columns, visited);
        }
        for (int i=0; i<columns; i++){
            dfs(board, 0, i, rows, columns, visited);
            dfs(board, rows-1, i, rows, columns, visited);
        }
        for (int i=1; i<rows-1; i++){
            for(int j=1; j<columns-1; j++){
                if (visited.find({i, j})==visited.end()){
                    board[i][j]='X';
                }
            }
        }
    }
};
