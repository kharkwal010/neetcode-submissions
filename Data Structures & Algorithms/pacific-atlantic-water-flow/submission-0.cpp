class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>> heights, set <pair<int, int>>& visited, int rows, int columns, int r, int c, int pre_height){
        if(r<0 || c<0 || r>=rows || c>=columns || heights[r][c]< pre_height || visited.find({r,c})!=visited.end()){
            return;
        }
        visited.insert({r,c});
        for(int i=0; i<4; i++){
            dfs(heights, visited, rows, columns, r+directions[i][0], c+directions[i][1], heights[r][c]);
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        set <pair<int,int>> paci;
        for(int i=0; i<columns; i++){
            dfs(heights, paci, rows, columns, 0, i, heights[0][i]);
        }
         for(int i=0; i<rows; i++){
            dfs(heights, paci, rows, columns, i, 0, heights[i][0]);
        }
        set <pair<int, int>> alt;
        for(int i=0; i<columns; i++){
            dfs(heights, alt, rows, columns, rows-1, i, heights[rows-1][i]);
        }
         for(int i=0; i<rows; i++){
            dfs(heights, alt, rows, columns, i, columns - 1, heights[i][columns - 1]);
        }
        vector<vector<int>> res;
        for (int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                if (alt.find({i, j})!=alt.end() && paci.find({i, j})!=paci.end()){
                    res.push_back({i, j});
                }
            }
        }
        return res;
        
    }
};
