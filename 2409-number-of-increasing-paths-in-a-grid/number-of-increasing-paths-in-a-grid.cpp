class Solution {
public:
    vector<vector<long long>> dp;
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int mod = 1e9+7;
    long long path(vector<vector<int>>& grid, int r, int c){
        if(dp[r][c]!=0) return dp[r][c];
        long long ans = 1;
        for(int i=0; i<4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr>=grid.size() || nr<0 || nc<0 || nc>=grid[0].size() || grid[nr][nc]<=grid[r][c]) continue;
            ans = (ans + path(grid, nr, nc))%mod;
        }
        return dp[r][c] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();        
        dp.resize(m, vector<long long>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]==0){
                    path(grid, i, j);
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = (ans + dp[i][j]) % mod;
            }
        }
        return ans;

    }
};