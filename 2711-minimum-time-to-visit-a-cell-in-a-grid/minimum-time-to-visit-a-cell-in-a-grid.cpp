class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>=2 && grid[1][0]>=2) return -1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, 0, 0});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while(!minheap.empty()){
            auto top = minheap.top();
            int time = top[0];
            int r = top[1];
            int c = top[2];
            minheap.pop();
            if(visited[r][c]) continue;
            visited[r][c] = true;
            if(r==n-1 && c==m-1) return time;
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nc<0 || nr<0 || nc==m || nr==n || visited[nr][nc]) continue;
                int timediff = grid[nr][nc] - time;
                if(timediff<0) minheap.push({time+1, nr, nc});
                else if(timediff%2==1) minheap.push({grid[nr][nc], nr, nc});
                else minheap.push({grid[nr][nc]+1, nr, nc});
            }
        }
        return -1;  // never reach here!       
    }
};