class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, 0, 0});
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            int time = top[0];
            int r = top[1];
            int c = top[2];
            if(visited[r][c]) continue;
            if(r==m-1 && c==n-1) return time;
            visited[r][c] = true;
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                // cout<<nr<<" "<<nc<<endl;
                if(nr<0 || nc<0 || nr==m || nc==n || visited[nr][nc]) continue;
                // cout<<"hello"<<endl;
                if(time>=moveTime[nr][nc]){
                    minheap.push({time+1, nr, nc});
                }
                else minheap.push({moveTime[nr][nc]+1, nr, nc});
            }
            
        }
        return -1;
    }
};