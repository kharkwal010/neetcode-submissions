class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       //check for rows;
       for (int i=0; i<9; i++){
        vector<int> check1(10,0);
        for(int j=0; j<9; j++){
            if (board[i][j]!='.'){
                check1[board[i][j]-'0']++;
                if (check1[board[i][j]-'0']>1){
                    return false;
                }

            }
        }
       }
       //check for columns;
        for (int j=0; j<9; j++){
        vector<int> check2(10,0);
        for(int i=0; i<9; i++){
            if (board[i][j]!='.'){
                check2[board[i][j]-'0']++;
                if (check2[board[i][j]-'0']>1){
                    return false;
                }

            }
        }
       }
       //check for box;
       for (int a=0; a<3; a++){
        for (int b=0; b<3; b++){
        vector<int> check3(10,0);
         for (int i=0+3*a; i<3+3*a; i++){
            for(int j=0+3*b; j<3+3*b; j++){
            if (board[i][j]!='.'){
                check3[board[i][j]-'0']++;
                if (check3[board[i][j]-'0']>1){
                    return false;
                }

            }
        }
       }
   
       }
       } 

       return true; 
    }
};
