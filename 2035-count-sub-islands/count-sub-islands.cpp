class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool& complete, int r, int c){
        if(r<0 || r>=grid1.size() || c<0 || c>=grid2[0].size() || grid2[r][c]==0) return;
        if(grid1[r][c]!=1) complete = false;
        grid2[r][c] = 0;
        for(int i=0; i<4; i++){
            dfs(grid1, grid2, complete, r+dir[i][0], c+dir[i][1]);
        }
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();  
        int count = 0;      
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j]==1){
                    bool complete = true;
                    dfs(grid1, grid2, complete, i, j);
                    if(complete) count++;
                }
            }
        }
        return count;
    }
};