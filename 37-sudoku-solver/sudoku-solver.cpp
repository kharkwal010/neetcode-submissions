class Solution {
public:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> block;
    vector<vector<char>> ans;
    void bfs(vector<vector<char>>& board, int& count){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    int b = 3*(i/3) + (j/3);
                    for(int k=1; k<=9; k++){
                        if(!row[i][k] && !col[j][k] && !block[b][k]){
                            char ch = k + '0';
                            board[i][j]  = ch;
                            row[i][k] = true;
                            col[j][k] = true;
                            block[b][k] = true;
                            count--;
                            bfs(board, count);
                            count++;
                            board[i][j]  = '.';
                            row[i][k] = false;
                            col[j][k] = false;
                            block[b][k] = false;                            
                        }
                    }
                    return;
                }
            }
        }
        if(count==0){
            ans = board;
        }
        return;
    }

    void solveSudoku(vector<vector<char>>& board) {
       row.resize(9, vector<bool>(10, false));
       col.resize(9, vector<bool>(10, false));
       block.resize(9, vector<bool>(10, false));
       int count = 0;
       for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                int b = 3*(i/3) + (j/3);
                if(board[i][j]!='.'){
                    int num = board[i][j]-'0';
                    row[i][num] = true;
                    col[j][num] = true;
                    block[b][num] = true;
                }
                else count++;
            }
       }
       bfs(board, count);
       board = ans;
       return;
    }
};