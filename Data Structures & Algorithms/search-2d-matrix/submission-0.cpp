class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first locate row and then column

        int left=0;
        
        int row  = matrix.size();
        int column = matrix[0].size();
        int right = row*column - 1;
        while (right>=left){
            if (matrix[0][0]==target){return true;}
            if (matrix[row-1][column-1] == target){return true;}
            int mid =( right + left )/ 2;
            int mid_row = mid/column;
            int mid_col = mid%column;
            if (matrix[mid_row][mid_col]==target){
                return true;
            }
            if (matrix[mid_row][mid_col]>target){
                right = mid_row*column + mid_col -1;
            }
            else if(matrix[mid_row][mid_col]<target){
                left = mid_row*column + mid_col +1;
            }

        }
        return false;
    }
};
