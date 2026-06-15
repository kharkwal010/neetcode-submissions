class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int peri = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    for(int a=0; a<4; a++){
                        int r = i+dir[a][0];
                        int c = j+dir[a][1];
                        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]==0){
                            peri++;
                        }
                    }
                }
            }
        }
        return peri;
    }
};