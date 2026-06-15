class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> pdia;
    unordered_set<int> ndia;
    void backtrack(int r, int n, vector<vector<string>>& ans, vector<string> board){
        if(r==n){
            ans.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            if(col.count(c) || pdia.count(c+r) || ndia.count(r-c)) continue;
            col.insert(c);
            pdia.insert(c+r);
            ndia.insert(r-c);
            board[r][c]='Q';
            backtrack(r+1, n, ans, board);
            board[r][c]='.';
            col.erase(c);
            pdia.erase(c+r);
            ndia.erase(r-c);
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<string> board(n,string(n,'.'));
      vector<vector<string>> ans;
        backtrack(0, n, ans, board);
        return ans;
    }
};
