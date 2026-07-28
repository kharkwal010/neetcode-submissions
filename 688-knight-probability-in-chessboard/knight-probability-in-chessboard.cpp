class Solution {
public:
    vector<vector<int>> dir = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2} , {-1, -2}, {1, -2}};
    vector<vector<vector<double>>> memo;

    double prob(int row, int col, int k, int& n){
        if(k==0) return 1;
        if(memo[row][col][k]!=-1) return memo[row][col][k];
        double ans = 0;
        for(int i=0; i<8; i++){
            int nr = row + dir[i][0];
            int nc = col + dir[i][1];
            if(nr>=n || nr<0 || nc>=n || nc<0) continue;
            ans += prob(nr, nc, k-1, n)/8;
        }
        return memo[row][col][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memo.resize(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return prob(row, column, k, n);
    }
};