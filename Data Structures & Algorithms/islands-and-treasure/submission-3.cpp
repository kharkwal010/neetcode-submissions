class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    set<pair<int, int>> visited;
    void islandsAndTreasure(vector<vector<int>>& grid){
        int rows = grid.size();
        int columns = grid[0].size();
        queue<pair<int, int>> queue;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j]==0){
                    queue.push({i, j});
                }
            }
        }
        while(!queue.empty()){
            auto top = queue.front();
            queue.pop();
            int r = top.first;
            int c = top.second;
            visited.insert({r,c});
            for(int i=0; i<4; i++){
                int cr = r+dir[i][0];
                int cc = c+dir[i][1];
                if(visited.find({cr,cc})==visited.end()){
                    if(cc>=0 && cr>=0 && cr<rows && cc<columns && grid[cr][cc]==INT_MAX){
                        grid[cr][cc]= grid[r][c]+1;
                        queue.push({cr, cc});
                    }
                }
            }
        }
        return;
    }
};
