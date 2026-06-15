class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> pdia;
    unordered_set<int> ndia;

    void ans(vector<string> board, vector<vector<string>>& res, int i, int n){
        if(i==n){
            res.push_back(board);
            return;
        }
        for(int r=0; r<n; r++){
            if(col.count(r) || pdia.count(i+r) || ndia.count(i-r)) continue;
            else{
                col.insert(r);
                pdia.insert(i+r);
                ndia.insert(i-r);
                board[r][i] = 'Q';
                ans(board, res, i+1, n);
                col.erase(r);
                pdia.erase(i+r);
                ndia.erase(i-r);
                board[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> res;
        ans(board, res, 0, n);
        return res;
    }
};
