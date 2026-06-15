class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int rows, int columns, int r, int c, vector<vector<int>>& grid, int& counter){
        if(r<0 || c<0 || r>=rows || c>=columns || grid[r][c]==0){
            return;
        }
        grid[r][c]=0;
        counter++;
        for(int i=0; i<4; i++){
            dfs(rows, columns, r+directions[i][0], c+directions[i][1], grid, counter);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int max_area=0;
        
        for(int i =0; i<rows; i++){
            for (int j=0; j<columns; j++){
                if(grid[i][j]==1){
                    int counter = 0;
                    dfs(rows, columns, i, j, grid, counter);
                    max_area = max(max_area, counter);
                    
                }
            }
        }
        return max_area;
    }
};
