class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int n){
        if(parent[n]==n) return n;
        else return parent[n] = find(parent[n]);
    }

    bool merge(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return false;
        if(size[pa]<size[pb]){
            size[pb]+=size[pa];
            parent[pa] = pb;
        }
        else{
            size[pa] += size[pb];
            parent[pb] = pa;
        }
        return true;
    }
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> visited;
    void dfs(vector<vector<int>>& grid, int r, int c, int& n){
        visited[r][c] = true;
        int one = n*r+c;
        for(int i=0; i<4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr<0 || nr>=n || nc<0 || nc>=n || visited[nr][nc] || grid[nr][nc]==0) continue;
            int two = n*nr+nc;
            merge(one, two);
            dfs(grid, nr, nc, n);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ele = n * n;
        size.resize(ele, 1);
        parent.resize(ele, 0);
        for(int i=0; i<ele; i++) parent[i] = i;
        visited.resize(n, vector<int>(n, false));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    count++;
                    continue;
                }
                if(visited[i][j]) continue;
                dfs(grid, i, j, n);                
            }
        }
        if(count==0) return ele;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    unordered_set<int> nei;
                    for(int a=0; a<4; a++){
                        int nr = i + dir[a][0];
                        int nc = j + dir[a][1];
                        if(nr>=n || nr<0 || nc<0 || nc>=n || grid[nr][nc]==0) continue;
                        int term = nr*n + nc;
                        nei.insert(find(term));
                    }
                    int large = 0;
                    for(int neigh: nei){
                        large += size[neigh];
                    }
                    ans = max(ans, 1+large);
                }
            }
        }
        return ans;
    }
};