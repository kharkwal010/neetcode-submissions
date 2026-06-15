class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int, int>> visited;
        int r = heights.size();
        int c = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0,0,0});
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int price = top[0];
            int row = top[1];
            int col = top[2];
            cout<<row<<","<<col<<","<<price<<endl;
            if(row==r-1 && col==c-1) return price;
            if(visited.count({row, col})) continue;
            visited.insert({row, col});
            for(int i=0; i<4; i++){
                int n_row = row + dir[i][0];
                int n_col = col + dir[i][1];
                if(n_row<0 || n_col<0 || n_row>=r || n_col>=c || visited.count({n_row, n_col})) continue;
                minheap.push({max(abs(heights[n_row][n_col] - heights[row][col]), price), n_row, n_col});
            }
        }
        return -1;

    }
};