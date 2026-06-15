class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r = matrix.size();
       int c = matrix[0].size();
       int top = 0;
       int bottom = r-1;
       while(top<bottom){
        int mid = (top+bottom)/2;
        if(matrix[mid][c-1]==target) return true;
        else if(matrix[mid][c-1]>target) bottom = mid;
        else top = mid + 1;
       }

       int left = 0;
       int right = c-1;
       while(left<=right){
        int mid = (left+right)/2;
        if(matrix[top][mid]==target) return true;
        else if(matrix[top][mid]<target) left = mid+1;
        else right = mid-1;
       }
       return false;

    }
};
