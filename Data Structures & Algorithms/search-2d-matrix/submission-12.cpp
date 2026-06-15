class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        //find the row:
        int start = 0;
        int last = row - 1;
        while(start<last){
            int mid = (start+last)/2;
            if(matrix[mid][col-1]>target){
                last = mid;
            }
            else if(matrix[mid][col-1]<target){
                start = mid + 1;
            }
            else{
                return true;
            }
        }
       row = start;
        start = 0;
        last = col -1;
        while(start<=last){
            int mid = (start+last)/2;
             if(matrix[row][mid]>target){
                last = mid-1;
            }
            else if(matrix[row][mid]<target){
                start = mid+1;
            }
            else{
                return true;
            }
        }
        return false;

    }
};
