class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int r, c;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                r = top.first + dir[i][0];
                c = top.second + dir[i][1];
                if(r>=0 && r<grid.size() && c<grid[0].size() && c>=0 && visited[r][c]==false && grid[r][c]==0){
                    grid[r][c] = grid[top.first][top.second] + 1;
                    q.push({r, c});
                }
            }
        }
        priority_queue<vector<int>> maxheap;
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), false));
        maxheap.push({grid[0][0], 0, 0});
        int ans = grid[0][0];
        visit[0][0] = true;
        while(!maxheap.empty()){
            auto top = maxheap.top();
            maxheap.pop();
            ans = min(top[0], ans);
            if(top[1]==grid.size()-1 && top[2]==grid[0].size()-1) return ans;
            for(int i=0; i<4; i++){
                r = top[1] + dir[i][0];
                c = top[2] + dir[i][1];
                if(r>=0 && r<grid.size() && c<grid[0].size() && c>=0 && visit[r][c]==false){
                    maxheap.push({grid[r][c], r, c});
                    visit[r][c] = true;
                }
            } 

        }
        return -1;
        
    }
};