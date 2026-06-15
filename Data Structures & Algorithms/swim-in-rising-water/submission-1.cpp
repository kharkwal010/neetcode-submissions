class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        set<pair<int, int>> visited;
        int ans = grid[0][0];
        minheap.push({ans, 0, 0});
        while(!minheap.empty()){
            auto top = minheap.top();
            ans = max(ans, top[0]);
            minheap.pop();
            int r = top[1];
            int c = top[2];
            if(r==grid.size()-1 && c==grid[0].size()-1) return ans;
            visited.insert({r,c});
            for(int i=0; i<4; i++){
                int row = r + dir[i][0];
                int col = c + dir[i][1];
                if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || visited.find({row, col})!= visited.end()){
                    continue;
                }
                minheap.push({grid[row][col], row, col});
            }
        }

    }
};
