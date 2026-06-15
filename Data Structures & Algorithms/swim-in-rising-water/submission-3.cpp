class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
         minheap.push({grid[0][0], 0, 0});
         set<pair<int, int>> visited;
         int ans = 0;

         while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();

            int r = top[1];
            int c = top[2];
            int val = top[0];
            visited.insert({r, c});
            ans = max(ans, val);
            if(r==row-1 && c==col-1) return ans;
            for(int i=0; i<4; i++){
                int new_r = r+dir[i][0];
                int new_c = c+dir[i][1];
                if(new_r<0 || new_r >=row || new_c<0 || new_c>=col || visited.find({new_r, new_c})!=visited.end()) continue;
                minheap.push({grid[new_r][new_c], new_r, new_c});
            }
         }
         return -1;
    }
};
