class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool frow = false;
        bool fcol = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<col; i++){
            if(matrix[0][i]==0){
                frow = true;
                break;
            }
        }
        for(int i=0; i<row; i++){
            if(matrix[i][0]==0){
                fcol = true;
                break;
            }
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // row to 0:
        for(int i=1; i<row; i++){
            if(matrix[i][0]==0){
                for(int j=0; j<col; j++){
                    matrix[i][j]=0;
                }
            }
        }
        // col to 0:
        for(int i=1; i<col; i++){
            if(matrix[0][i]==0){
                for(int j=0; j<row; j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(frow){
            for(int i=0; i<col; i++){
                matrix[0][i]=0;
            }
        }
        if(fcol){
            for(int i=0; i<row; i++){
                matrix[i][0]=0;
            }
        }
    }
};
