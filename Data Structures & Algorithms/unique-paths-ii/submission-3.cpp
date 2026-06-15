class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[row-1][column-1]==1){
            return 0;
        }
        for(auto& items: obstacleGrid){
            items.push_back(0);
        }
        vector<int> newr(column+1, 0);
        obstacleGrid.push_back(newr);
        
        obstacleGrid[row-1][column-1]=1;
        for(int i=row-1; i>=0; i--){
            for(int j=column-1; j>=0; j--){
                if(i==row-1 && j==column-1){
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    obstacleGrid[i][j]=0;
                    continue;
                }
                obstacleGrid[i][j]=obstacleGrid[i][j+1] + obstacleGrid[i+1][j];
            }
        }
        return obstacleGrid[0][0];
    }
};