class Solution {
public:    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n*n+1, false);
        queue<int> q;
        q.push(1);
        int count = 0;
        visited[1]=true;
        while(!q.empty()){
            int sz = q.size();
            // cout<<sz<<endl;
            for(int i=0; i<sz; i++){
                int curr = q.front();
                // cout<<curr<<endl;
                if(curr==n*n) return count;
                q.pop();
                for(int i=1; i<=6; i++){
                    int newi = curr + i;
                    if(newi>n*n) break;
                    int r = n-1 - (newi-1)/n;
                    int c = (newi-1)%n;
                    if(((newi-1)/n)%2==1) c = n-1 - c;
                    if(board[r][c]!=-1){
                        newi = board[r][c];
                    }
                    if(visited[newi]) continue;
                    visited[newi] = true;
                    q.push(newi);
                }
            }
            // cout<<endl;
            count++;
            
        }
        return -1;
    }
};