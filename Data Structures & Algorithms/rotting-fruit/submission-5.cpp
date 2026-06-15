class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
       int rows = grid.size();
       int columns = grid[0].size();
       int count1 = 0;
       queue<pair<int, int>> queue;
       for(int i=0; i<rows; i++){
        for(int j =0; j<columns; j++){
            if(grid[i][j]==1){
                count1++;
            }
            else if(grid[i][j]==2){
                queue.push({i,j});
            }
        }
       }

        int time = 0;
        while(!(queue.empty())){
            vector<pair<int,int>> layer;
            while(!(queue.empty())){
                auto coor = queue.front();
                int r = coor.first;
                int c = coor.second;
                queue.pop();
                for(int i=0; i<4; i++){
                    int row = r+dir[i][0];
                    int column = c+dir[i][1];
                    if(row>=0 && column>=0 && row<rows && column<columns && grid[row][column]==1){
                        layer.push_back({row, column});
                        grid[row][column]=2;
                        count1--;
                    }
                }
            }
            time++;
            for(auto elements: layer){
                queue.push({elements.first, elements.second});
            }
        }
        if(count1>0){
            return -1;
        }
        return max(time-1, 0);
    }
};
