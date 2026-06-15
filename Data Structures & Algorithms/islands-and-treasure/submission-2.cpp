class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> queue;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0){
                    queue.push({i,j});
                }
            }
        }
        while(!queue.empty()){
            auto coor = queue.front();
            int a= coor.first;
            int b= coor.second;
            queue.pop();
            for(int i=0; i<4; i++){
                int row = a+dir[i][0];
                int column = b+dir[i][1];
                if(row>=0 && column<grid[0].size() && column>=0 && row <grid.size() && grid[row][column]==INT_MAX){
                    queue.push({a+dir[i][0],b+dir[i][1]});
                    grid[row][column]= grid[a][b]+1;
                }
            }

        }
        return;
    }
};
