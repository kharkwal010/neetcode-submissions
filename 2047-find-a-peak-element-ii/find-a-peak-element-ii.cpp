class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size()-1;
        while(l<=r){
            int m = (l + r) / 2;
            int maxi = 0;
            int row = -1;
            for(int i=0; i<matrix.size(); i++){
                if(maxi<matrix[i][m]){
                    maxi = matrix[i][m];
                    row = i;
                }
            }
            if(m>0 && matrix[row][m-1]>matrix[row][m]) r = m-1;
            else if(m<matrix[0].size()-1 && matrix[row][m+1]>matrix[row][m]) l = m+1;
            else return {row, m};
        }
        return {-1,-1};
    }
};