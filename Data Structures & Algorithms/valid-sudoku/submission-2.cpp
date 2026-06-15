class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       //check for rows;
       for (int i=0; i<9; i++){
        unordered_map<char, int> check;
        for(int j=0; j<9; j++){
            if (board[i][j]!='.'){
                check[board[i][j]]++;
                if (check[board[i][j]]>1){
                    return false;
                }

            }
        }
        check.clear();
       }
       //check for columns;
        for (int j=0; j<9; j++){
        unordered_map<char, int> check;
        for(int i=0; i<9; i++){
            if (board[i][j]!='.'){
                check[board[i][j]]++;
                if (check[board[i][j]]>1){
                    return false;
                }

            }
        }
        check.clear();
       }
       //check for box;
       for (int a=0; a<3; a++){
        for (int b=0; b<3; b++){
        unordered_map<char, int> check;
         for (int i=0+3*a; i<3+3*a; i++){
        for(int j=0+3*b; j<3+3*b; j++){
            if (board[i][j]!='.'){
                check[board[i][j]]++;
                if (check[board[i][j]]>1){
                    return false;
                }

            }
        }
       }
       check.clear();
       }
       } 

       return true; 
    }
};
