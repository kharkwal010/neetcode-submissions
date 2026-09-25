class Solution {
public:
    vector<vector<vector<long long>>> memo;
    long long costing(vector<vector<int>>& cost, int i, int j, int k){
        if(i==cost.size()/2) return 0;
        if(memo[i][j][k]!=-1) return memo[i][j][k];
        long long ans = LLONG_MAX;
        int r = cost.size() - i - 1;
        for(int x=0; x<3; x++){
            if(x==j) continue;
            for(int y=0; y<3; y++){
                if(y==x || y==k) continue;
                ans = min(ans, cost[i][x] + cost[r][y] + costing(cost, i+1, x, y));
            }
        }
        return memo[i][j][k] = ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        memo.resize(n, vector<vector<long long>>(4, vector<long long>(4, -1)));
        return costing(cost, 0, 3, 3);

    }
};