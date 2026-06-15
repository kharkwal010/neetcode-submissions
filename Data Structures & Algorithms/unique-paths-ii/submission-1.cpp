class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        if(obstacleGrid[0][0]!=obstacleGrid[row-1][column-1]){
            return 0;
        }
        set<pair<int, int>> visited;
        int obs = 1;
     
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(obstacleGrid[i][j]==obs){
                    visited.insert({i,j});
                }
            }
        }
        vector<vector<int>> dp(row, vector<int>(column,1));
        bool zero = false;
        for(int i=row-1; i>=0; i--){
            if(zero || visited.find({i, column-1})!=visited.end()){
                zero = true;
                dp[i][column-1]=0;
            }
        }
        zero = false;
        for(int i=column-1; i>=0; i--){
            if(zero || visited.find({row-1, i})!=visited.end()){
                zero = true;
                dp[row-1][i]=0;
            }
        }
        for(int i=row-2; i>=0; i--){
            for(int j=column-2; j>=0; j--){
                if(visited.find({i,j})!=visited.end()){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};