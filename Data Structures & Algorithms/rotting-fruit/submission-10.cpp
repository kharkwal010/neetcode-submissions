class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid[0].size();
       int fresh = 0;
       int time=0;
       queue<pair<int, int>> rotton;
    
       for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]==1){
                fresh++;
            }
            else if(grid[i][j]==2){
                rotton.push({i,j});
            }
        }
       }

      while(!rotton.empty()){
            int size = rotton.size();
            for(int i=0; i<size; i++){
                auto top = rotton.front();
                rotton.pop();
                int r=top.first;
                int c=top.second;
                for(int i=0; i<4; i++){
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1){
                        rotton.push({nr, nc});
                        fresh--;
                        grid[nr][nc] = 2;
                    }
                }
            }
            time++;
      }
      if(fresh>0) return -1;
      return max(time-1, 0);
    }
};
