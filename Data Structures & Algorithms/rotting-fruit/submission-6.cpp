class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> rotten;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    rotten.push({i,j});
                }
            }
        }
        int time = 0;
        while(!rotten.empty()){
            vector<pair<int, int>> layer;
            while(!rotten.empty()){
                auto top = rotten.front();
                int r = top.first;
                int c = top.second;
                rotten.pop();
                for(int i=0; i<4; i++){
                    int nrow = r+dir[i][0];
                    int ncol = c+dir[i][1];
                    if(nrow>=0 && ncol>=0 && nrow<row && ncol<col && grid[nrow][ncol]==1){
                      grid[nrow][ncol]=2;
                      layer.push_back({nrow,ncol});
                      fresh--;
                    }
                }
            }
                time++;
                for(auto ele: layer){
                    rotten.push(ele);
                }
        }
        if(fresh>0){
            return -1;
        }
        return max(time-1,0);

    }
};
