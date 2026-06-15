class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> pdia;
    unordered_set<int> ndia; 
    void queen(vector<string>& board, vector<vector<string>>& comb, int r, int n){
        if(r==n){
            comb.push_back(board);
        }
        for(int i=0; i<n; i++){
            if(!(col.count(i) || pdia.count(r+i) || ndia.count(r-i))){
                board[r][i]='Q';
                col.insert(i);
                pdia.insert(r+i);
                ndia.insert(r-i);
                queen(board, comb, r+1, n);
                board[r][i]='.';
                col.erase(i);
                pdia.erase(r+i);
                ndia.erase(r-i);
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> comb;
        queen(board, comb, 0, n);
        return comb;        
    }
};
