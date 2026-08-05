class Solution {
public:
    vector<vector<vector<int>>> memo;
    int pickup(vector<vector<int>>& grid, int row, int one, int two, int& col){
        if(row==grid.size()) return 0;
        if(memo[row][one][two]!=-1) return memo[row][one][two];
        int ans = 0;
        for(int i=-1; i<=1; i++){
            int l = one + i;
            if(l<0 || l>=col) continue;
            for(int j=-1; j<=1; j++){                
                int r = two + j;
                if(r<=l || r>=col) continue;
                ans = max(ans, grid[row][one] + grid[row][two] + pickup(grid, row+1, l, r, col));
            }
        }
        return memo[row][one][two] = ans; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        memo.resize(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return pickup(grid, 0, 0, c-1, c);
    }
};