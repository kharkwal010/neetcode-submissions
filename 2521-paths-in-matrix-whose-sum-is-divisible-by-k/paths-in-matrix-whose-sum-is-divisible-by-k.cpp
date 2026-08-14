class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9+7;
        vector<vector<unordered_map<int, long long>>> dp(m, vector<unordered_map<int, long long>>(n));
        dp[m-1][n-1][grid[m-1][n-1]%k]++ ;
        for(int i=m-2; i>=0; i--){
            for(auto& ele: dp[i+1][n-1]){
                int curr = (ele.first + grid[i][n-1]) % k;
                dp[i][n-1][curr]++;
            }
            
        }
        for(int i=n-2; i>=0; i--){
            for(auto& ele: dp[m-1][i+1]){
                int curr = (ele.first + grid[m-1][i]) % k;
                dp[m-1][i][curr]++;
            }
            
        }
        for(int i = m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                for(auto& ele: dp[i+1][j]){
                    int curr = (grid[i][j] + ele.first)%k;
                    dp[i][j][curr] = (dp[i][j][curr] + ele.second)%mod;
                }
                for(auto& ele: dp[i][j+1]){
                    int curr = (grid[i][j] + ele.first)%k;
                    dp[i][j][curr] = (dp[i][j][curr] + ele.second)%mod;
                }
            }
        }
        return dp[0][0][0];
    }
};