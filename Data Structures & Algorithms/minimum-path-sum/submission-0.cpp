class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(auto& items: grid){
            items.push_back(0);
        }
        vector<int> newr(grid[0].size()+1,0);
        grid.push_back(newr);
        for(int i=grid.size()-2; i>=0; i--){
            for(int j=grid[0].size()-2; j>=0; j--){
                if(i==grid.size()-2){
                    grid[i][j]=grid[i][j]+grid[i][j+1];
                }
                else if(j==grid[0].size()-2){
                    grid[i][j]=grid[i][j]+grid[i+1][j];
                }
                else grid[i][j]=min(grid[i][j]+grid[i][j+1], grid[i][j]+grid[i+1][j]);
            }
        }
        return grid[0][0];
    }
};