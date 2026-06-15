class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    set<pair<int, int>> visited;  
    void search(vector<vector<char>>& board, int rows, int columns, int i, int j, string word, int count, bool& ans){
        if(i<0 || i>=rows || j<0 || j>=columns || board[i][j]!= word[count] || visited.find({i, j})!=visited.end()){
            return;
        }
        if(count == word.size()-1){
            ans = true;
            return;
        }
        visited.insert({i, j});        
        for(int a=0; a<4; a++){
            search(board, rows, columns, i+ dir[a][0], j+dir[a][1], word, count+1, ans);
        }
        visited. erase({i,j});
        
        return;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows=  board.size();
        int columns = board[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(board[i][j]==word[0]){ 
                    bool present = false;
                    search(board, rows, columns, i, j, word, 0, present);
                    if(present){
                        return true;
                    }
                }
            }
        }
        return false;
       
    }
};
