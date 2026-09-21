class Solution {
public:    
    int snakesAndLadders(vector<vector<int>>& board) {
       int n = board.size();
       vector<int> visited(n*n+1, false);
       queue<int> q;
       q.push(1);
       visited[1] = true;
       int count = 1;
       while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int curr = q.front();
                q.pop();
                for(int j=1; j<=6; j++){
                    int m = curr + j;
                    int x = (m-1)/n;
                    int r = n-1 - x;
                    int c = (m-1)%n;
                    if(x%2==1) c = n-1 - c;
                    // cout<<r<<" "<<c<<endl;
                    if(board[r][c]!=-1) m = board[r][c];
                    if(visited[m]) continue;
                    if(m==n*n) return count;
                    visited[m] = true;
                    q.push(m);

                }
            }
            count++;
       }
       return -1;
       
    }
};