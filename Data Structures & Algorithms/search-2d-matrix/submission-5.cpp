class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int one = 0;
        int last = matrix.size()-1;
        int row = 0;
        // its the row:
        while (one<=last){
            int mid = (one + last) / 2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target){
                row = mid;
                break;
            }
            if(matrix[mid][0] < target){
                one = mid + 1;
            }
            else{
                last = mid - 1;
            }
        }
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = (left + right) / 2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]>target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;

    }
};
