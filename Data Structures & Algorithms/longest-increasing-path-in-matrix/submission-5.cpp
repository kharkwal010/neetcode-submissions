class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int prev, int i, int j, int r, int c){
        if(prev>=matrix[i][j]) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        int ans = 0;
        for(int n=0; n<4; n++){
            int row = i+dir[n][0];
            int col = j+dir[n][1];
            if(row<0 || col<0 || row>=r || col>=c) continue;
             ans = max(ans, 1 + dfs(matrix, dp, matrix[i][j], row, col, r, c));
        } 
        dp[i][j]=max(1,ans);
        return dp[i][j]; 
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans = max(ans, dfs(matrix, dp, INT_MIN, i, j, r, c));
            }
        }
        return ans;
    }
};
