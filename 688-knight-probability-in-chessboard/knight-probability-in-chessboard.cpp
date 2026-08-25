class Solution {
public:
    vector<vector<int>> dir = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
    vector<vector<vector<double>>> memo;
    double prob(int n, int k, int r, int c){
        if(k==0) return 1.0;
        if(memo[r][c][k]!=-1) return memo[r][c][k];
        double ans = 0;
        for(int i=0; i<8; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr<0 || nc<0 || nc>=n || nr>=n) continue;
            ans += 1.0/8*prob(n, k-1, nr, nc);
        }                
        return memo[r][c][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memo.resize(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return prob(n, k, row, column);
    }
};