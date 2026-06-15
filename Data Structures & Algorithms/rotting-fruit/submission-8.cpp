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
            if( grid[i][j]==1){
                fresh++;
            }
            else if(grid[i][j]==2){
                rotton.push({i,j});
            }
        }
       }

       while(!rotton.empty()){
        vector<pair<int, int>> layer;
        while(!rotton.empty()){
            auto top = rotton.front();
            rotton.pop();
            for(int i=0; i<4; i++){                
            int r = top.first+dir[i][0];
            int c = top.second+dir[i][1];
            if(r>=0 && r<row && c>=0 && c<col && grid[r][c]==1){
                layer.push_back({r,c});
                grid[r][c]=2;
                fresh--;
             }
            }        
        }
        time++;
        for(auto ele: layer){
            rotton.push(ele);
        }

       }
       if(fresh>0){
        return -1;
       }
       else  return max(time-1,0);
    }
};
