class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({grid[0][0], 0, 0});
        set<pair<int, int>> visited;
        int ans = 0;
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            ans = max(ans, top[0]);
            if(top[1]==grid.size()-1 && top[2] == grid[0].size()-1) return ans;
            visited.insert({top[1], top[2]});
            for(int i=0; i<4; i++){
                int r= dir[i][0] + top[1];
                int c= dir[i][1] + top[2];
                if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || visited.count({r, c})) continue;
                minheap.push({grid[r][c], r, c});
            }
        }
        return -1;
    }
};
