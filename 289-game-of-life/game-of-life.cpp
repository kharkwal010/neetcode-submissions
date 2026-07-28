class Solution {
public:
    vector<vector<int>> dir = {{-1,-1}, {0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}};
    int neigh(vector<vector<int>>& board, int& r, int& c, int& row, int& col){
        int count = 0;
        for(int i=0; i<8; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr<0 || nr>=row || nc<0 || nc>=col || board[nr][nc]<=0) continue;
            count++;
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i = 0; i<r; i++){
            for(int j=0; j<c; j++){
                int nei = neigh(board, i, j, r, c);
                if(board[i][j]==0){
                    board[i][j] = -1*nei;
                }
                else{
                    if(nei==0) board[i][j] = INT_MAX;
                    else board[i][j] = nei;
                }
            }
        }


        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int term = board[i][j];
                if(term==INT_MAX) board[i][j] = 0;
                if(term==-3) board[i][j] = 1;
                else if(term<=0) board[i][j] = 0;
                else if(term==2 || term==3) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
        return;
    }
};