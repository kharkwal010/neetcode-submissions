class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> pdia;
    unordered_set<int> ndia;

    void dfs(vector<string> board, vector<vector<string>>& ans, int r){
        if(r==board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<board.size(); i++){
            if(col.count(i) || pdia.count(i+r) || ndia.count(i-r)) continue;
            board[r][i] ='Q';
            col.insert(i);
            pdia.insert(i+r);
            ndia.insert(i-r);
            dfs(board, ans, r+1);
            board[r][i] = '.';
            col.erase(i);
            pdia.erase(i+r);
            ndia.erase(i-r);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        dfs(board, ans, 0);
        return ans;
    }
};
