class Solution {
public:
    set<pair<int, int>> visited;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void check(vector<vector<char>>& board, int r, int c, int row, int col ){
        if(r>=row || r<0 || c>=col|| c<0 || board[r][c]=='X' || visited.find({r,c})!=visited.end()){
            return;
        }
        visited.insert({r,c});
        for(int i=0; i<4; i++){
            int nr = r+ dir[i][0];
            int nc = c+ dir[i][1];
            check(board, nr, nc, row, col);
        }
        return;
    }
    
    void solve(vector<vector<char>>& board){
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++){
            if(board[i][0]=='O'){
                check(board, i, 0, row, col);
            }
            if(board[i][col-1]=='O'){
                check(board,i, col-1, row, col);
            }
        } 
        for(int i=0; i<col; i++){
            if(board[0][i]=='O'){
                check(board, 0, i, row, col);
            }
            if(board[row-1][i]=='O'){
                check(board, row-1, i, row, col);
            }
        } 
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(visited.find({i,j})==visited.end()){
                    board[i][j]='X';
                }
            }
        } 
        return;     
    }
};
