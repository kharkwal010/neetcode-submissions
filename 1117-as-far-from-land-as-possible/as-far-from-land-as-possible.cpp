class Solution {
public:
    vector<vector<int>> dir = {{0,-1}, {0,1}, {-1, 0}, {1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)q.push({i, j});
            }
        }
        if(q.size()==0 || q.size()==n*n) return -1;
        int ans = 1;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr<0 || nc<0 || nr>=n || nc>=n || grid[nr][nc]!=0) continue;
                grid[nr][nc] = grid[r][c] + 1;
                ans = max(ans, grid[nr][nc]);
                q.push({nr, nc});
            }
        }
        return ans - 1;

    }
};