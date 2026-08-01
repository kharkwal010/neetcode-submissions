class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int down = matrix.size()-1;
        int right = matrix[0].size()-1;
        int up = 0;
        int left = 0;
        while(left<=right && up<=down){
            int l = left;
            int r = right;
            while(left<=right){
                int m = (left+right) / 2;
                if(matrix[up][m]<target) left = m+1;
                else if(matrix[up][m]>target) right = m-1;
                else return true;
            }
            int u = up;
            int d = down;
            while(up<=down){
                int m = (up+down) / 2;
                if(matrix[m][l]<target) up = m+1;
                else if(matrix[m][l]>target) down = m-1;
                else return true;
            }
            right = left - 1;
            left = l + 1;
            down = up - 1;
            up = u+1;
        }
        return false;
        
    }
};