class Solution {
public:
    vector<vector<int>> memo;
    int sum(vector<vector<int>>& grid, int j, int prev){
        if(j==grid.size()) return 0;
        if(memo[j][prev]!=INT_MIN) return memo[j][prev];
        int ans = INT_MAX;
        for(int i=0; i<grid.size(); i++){
            if(i==prev) continue;
            ans = min(ans, grid[j][i] + sum(grid, j+1, i));
        }
        return memo[j][prev] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        memo.resize(n, vector<int>(n+1, INT_MIN));
        return sum(grid, 0, n);

    }
};