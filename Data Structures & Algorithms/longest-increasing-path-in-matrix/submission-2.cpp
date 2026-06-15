class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c, int row, int col, int prev){
        if(prev>=matrix[r][c]){
            return 0;
        }
        if(dp[r][c]!=0){
            return dp[r][c];
        }
        for(int i=0; i<4; i++){
            int cr = r + dir[i][0];
            int cc = c + dir[i][1];
            if(cr<0 || cc <0 || cr >= row || cc>=col){
                continue;
            }
            dp[r][c] = max(dp[r][c], 1 + dfs(matrix, dp, cr, cc, row, col, matrix[r][c]));
        }
        if(dp[r][c]==0) dp[r][c] = 1;

        return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans = max(ans, dfs(matrix, dp, i, j, row, col, INT_MIN));
            }
        }
        return ans;

    }
};
