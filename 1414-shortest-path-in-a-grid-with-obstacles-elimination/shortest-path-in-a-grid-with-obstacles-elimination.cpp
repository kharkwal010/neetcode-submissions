class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(k+1, false)));
        queue<vector<int>> q;
        q.push({0,0,k});
        visited[0][0][k] = true;
        int count = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                auto curr = q.front();
                q.pop();
                int r = curr[0];
                int c = curr[1];
                if(r==m-1 && c==n-1) return count;
                int level = curr[2];
                for(int i=0; i<4; i++){
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
                    int clevel = level;
                    if(grid[nr][nc]==1) clevel -= 1;
                    if(clevel<0 || visited[nr][nc][clevel]) continue;
                    visited[nr][nc][clevel] = true;
                    q.push({nr, nc, clevel});
                }                
            }
            count++;          
            
        }
        return -1;
    }
};