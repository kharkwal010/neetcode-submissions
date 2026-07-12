class Solution {
public:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> box;

    bool check(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(int k=1; k<10; k++){
                        int b = (j/3) + (i/3) * 3; 
                        if(row[i][k] || col[j][k] || box[b][k]) continue;
                        board[i][j] = '0' + k;
                        row[i][k] = true;
                        col[j][k] = true;
                        box[b][k] = true;
                        if(check(board)) return true;
                        board[i][j] = '.';
                        row[i][k] = false;
                        col[j][k] = false;
                        box[b][k] = false;                       
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9, vector<bool>(10, false));
        col.resize(9, vector<bool>(10, false));
        box.resize(9, vector<bool>(10, false));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int term = board[i][j]-'0';
                    row[i][term] = true;
                    col[j][term] = true;
                    int b = (j/3) + (i/3) * 3;
                    box[b][term] = true;
                }
            }
        }
        check(board);
        return;
    }
};