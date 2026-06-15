class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        int ans = grid[0][0];
        set<pair<int, int>> visited;
        minheap.push({ans, 0, 0});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            ans = max(ans, top[0]);
            visited.insert({top[1], top[2]});
            if(top[1]==grid.size()-1 && top[2]==grid[0].size()-1) return ans;
            for(int i=0; i<4; i++){
                int r = top[1]+dir[i][0];
                int c = top[2]+dir[i][1];
                if(r<0 || c<0 ||r>=grid.size() || c>=grid[0].size() || visited.find({r,c})!=visited.end()) continue;
                minheap.push({grid[r][c], r, c});
            }
        }
    }
};
