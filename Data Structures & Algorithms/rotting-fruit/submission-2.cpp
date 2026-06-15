class Solution {
public:
    vector<vector<int>> direction = {{1,0},{-1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int count1 = 0;
        queue<pair<int, int>> queue;
        for (int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                if(grid[i][j]==1){
                    count1++;
                }
                if(grid[i][j]==2){
                    queue.push({i,j});
                }
            }
        }
        int time = 0;
        
        while(!(queue.empty())){
            bool change =false;
            int size = queue.size();
            for (int j=0; j<size; j++){
            int row = queue.front().first;
            int column = queue.front().second;
            queue.pop();
            for(int i=0; i<4; i++){
                int r = row + direction[i][0];
                int c =column + direction[i][1];
                if (r<0 || c<0 || r>=rows || c>= columns || grid[r][c]!=1){
                    continue;
                }
                count1--;
                grid[r][c]=2;
                change = true;
                queue.push({r,c});
            }
            }
            if (change==true){
                time++;
                }
        }
        if (count1==0){
            return time;
        }
        else{
            return -1;
        }

    }
};
