class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    void move(vector<vector<int>>& grid, int count, int& ans, int r, int c, int& sum){
        if(grid[r][c]==2){
            // cout<<count<<endl;
            if(count==sum-1) ans++;
            return;
        }
        // cout<<r<<" "<<c<<" "<<grid[r][c]<<endl;
        for(int i=0; i<4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || grid[nr][nc]==1 || grid[nr][nc]==-1) continue;
            grid[r][c] = 1;
            move(grid, count+1, ans, nr, nc, sum);
            grid[r][c] = 0;
        }
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int r = 0;
        int c = 0;
        int sum = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    r = i;
                    c = j;
                }
                if(grid[i][j]==-1) continue;
                sum++;
            }
        }
        // cout<<r<<" "<<c<<endl;
        // cout<<sum<<endl;
        move(grid, 0, ans, r, c, sum);
        return ans;
    }
};