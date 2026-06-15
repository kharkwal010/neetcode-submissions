class Solution {
public:
   
   vector<vector<int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};
    int dp(vector<vector<int>>& matrix, int r, int c, int row, int column, int prev, vector<vector<int>>& memo){
        if(r<0 || r>=row || c<0 || c>=column || prev>=matrix[r][c]) return 0;
        if(memo[r][c]!=0) return memo[r][c];
        int num = 0;
        for(int i=0; i<4; i++){
            num = max(num, 1+dp(matrix, r+dir[i][0], c+dir[i][1], row, column, matrix[r][c], memo));
        }
        memo[r][c] = num;
        return num;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans = max(ans, dp(matrix, i, j, row, col, INT_MIN, memo));
            }
        }
        return ans;
    }
};
