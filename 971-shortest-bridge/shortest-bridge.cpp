class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    void dfs(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& q, int n){
        q.push({r, c});
        for(int i=0; i<4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr<0 || nr>=n || nc<0 || nc>=n || grid[nr][nc]!=1) continue;
            grid[nr][nc] = 2;
            dfs(grid, nr, nc, q, n);
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        for(int i=0; i<n; i++){
            bool got = false;
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    grid[i][j]=2;
                    dfs(grid, i, j, q, n);
                    got = true;
                    break;
                }
            }
            if(got) break;
        }
        int count = 0;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                pair<int, int> terms = q.front();
                q.pop();
                int r = terms.first;
                int c = terms.second;
                for(int j=0; j<4; j++){
                    int nr = r + dir[j][0];
                    int nc = c + dir[j][1];
                    if(nr<0 || nr>=n || nc<0 || nc>=n || grid[nr][nc]==2) continue;
                    if(grid[nr][nc]==1) return count;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
                
            }
            count++;
        }
        return -1;
    }
};