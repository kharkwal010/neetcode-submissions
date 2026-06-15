class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    bool dfs(vector<vector<char>>& board, string word, int i, vector<vector<bool>>& visited, int r, int c){
        if(i==word.size()) return true;
        bool ans = false;
        for(int j=0; j<4; j++){
            int nr = r + dir[j][0];
            int nc = c + dir[j][1];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && !visited[nr][nc] && board[nr][nc]==word[i]){
                visited[nr][nc] = true;
                ans = ans || dfs(board, word, i+1, visited, nr, nc);
                visited[nr][nc] = false;
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bool present = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    visited[i][j] = true;
                    present = dfs(board, word, 1, visited, i, j);
                    visited[i][j] = false;
                    if(present) return true;
                }
            }
        }
        return false;

    }
};
