class Solution {
public:
    set<pair<int, int>> visited;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void check(vector<vector<char>>& board, int r, int c, int row, int col){
        if(r<0 || r>=row || c<0 || c>=col || board[r][c]=='X' || visited.count({r,c}))
            return;

        visited.insert({r,c});
        for(int i=0; i<4; i++){
            check(board, r+dir[i][0], c+dir[i][1], row, col);
        }
    }

    void solve(vector<vector<char>>& board){
        int row = board.size();
        int col = board[0].size();

        // First & last column
        for(int i=0; i<row; i++){
            if(board[i][0]=='O'){
                check(board, i, 0, row, col);
            }
            if(board[i][col-1]=='O'){
                check(board, i, col-1, row, col);
            }
        }

        // First & last row
        for(int j=0; j<col; j++){
            if(board[0][j]=='O'){
                check(board, 0, j, row, col);
            }
            if(board[row-1][j]=='O'){   // ✅ fixed
                check(board, row-1, j, row, col);
            }
        }

        // Convert unvisited 'O' → 'X'
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O' && visited.count({i,j})==0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
