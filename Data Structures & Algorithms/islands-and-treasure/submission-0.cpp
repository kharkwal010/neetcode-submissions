class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows=grid.size();
        int columns = grid[0].size();
        queue<pair<int,int>> queue;
        for (int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j]==0){
                        queue.push({i,j});
                }
            }
        }
        int maxi= INT_MAX;
        while(!(queue.empty())){
            auto member = queue.front();
            int row = member.first;
            int column = member.second;
            queue.pop();
            for(int i=0; i<4; i++){
               int r =row+ dir[i][0];
               int c = column + dir[i][1];
                if (r<0 || c<0 || r>=rows|| c>=columns || grid[r][c] !=maxi){
                    continue;
                }
                grid[r][c]=grid[row][column]+1;
                queue.push({r,c});
            }

        }
    }
};
