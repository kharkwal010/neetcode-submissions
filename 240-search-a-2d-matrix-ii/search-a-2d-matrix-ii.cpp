class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c = matrix[0].size() - 1;
        int r = 0;
        while(r<matrix.size() && c>=0){
            if(matrix[r][c]<target) r++;
            else if(matrix[r][c]>target) c--;
            else return true;
        }
        return false;        
    }
};