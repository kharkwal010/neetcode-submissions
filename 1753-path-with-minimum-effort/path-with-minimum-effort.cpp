class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        minheap.push({0, 0, 0});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int r = top[1];
            int c = top[2];
            int cost = top[0];
            if(visited[r][c]) continue;
            visited[r][c] = true;
            if(r==m-1 && c==n-1) return cost;
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr<0 || nc<0 || nr>=m || nc>=n || visited[nr][nc]) continue;
                int curr = abs(heights[r][c] - heights[nr][nc]);
                curr = max(cost, curr);
                minheap.push({curr, nr, nc});
            }
        }
        return -1;

    }
};