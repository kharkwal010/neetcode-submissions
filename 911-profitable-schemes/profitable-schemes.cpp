class Solution {
public:
   vector<vector<vector<int>>> memo;
   int mod = 1e9+7;
   int solve(int n, int mprofit, vector<int>& group, vector<int>& profit, int i){
        if(i==group.size()) return (mprofit==0);
        if(memo[i][mprofit][n]!=-1) return memo[i][mprofit][n];
        long long ans = 0;
        ans = (ans + solve(n, mprofit, group, profit, i+1))%mod;
        if(n-group[i]>=0){
            int newprofit = max(0, mprofit - profit[i]);
            ans = (ans +  solve(n - group[i], newprofit, group, profit, i+1))%mod;
        }
        return memo[i][mprofit][n] = ans;           
        
   }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit){
        int j = group.size();
        memo.resize(j, vector<vector<int>>(minProfit+1, vector<int>(n+1, -1)));
        return solve(n, minProfit, group, profit, 0);
    }
};