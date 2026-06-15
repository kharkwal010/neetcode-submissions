class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        prefix.resize(r+1, vector<int>(c+1, 0));
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int all = prefix[row2+1][col2+1];
        int top = prefix[row1][col2+1];
        int left = prefix[row2+1][col1];
        int check = prefix[row1][col1];
        return all - top - left + check;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */