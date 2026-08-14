class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,1}, {1,-1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        visited[0][0] = true;
        q.push({0,0});
        int count = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto top = q.front();
                q.pop();
                int r = top.first;
                int c = top.second;
                if(r==n-1 && c==n-1) return count;

                for(int i=0; i<8; i++){
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(nr<0 || nc<0 || nr>=n || nc>=n || grid[nr][nc]==1 || visited[nr][nc]) continue;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            count++;            
        }
        return -1;

    }
};