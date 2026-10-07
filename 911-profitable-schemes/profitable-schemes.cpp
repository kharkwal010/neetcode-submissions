class Solution {
public:
    vector<vector<vector<int>>> memo;
    int mod = 1e9+7;
    int profits(int n, int mprofit, vector<int>& group, vector<int>& profit, int i){
        if(i==group.size()) return (mprofit==0);
        if(memo[n][mprofit][i]!=-1) return memo[n][mprofit][i];
        long long ans = 0;
        ans = (ans + profits(n, mprofit, group, profit, i+1))%mod;
        if(group[i]<=n){
            int newprofit = max(0, mprofit - profit[i]);
            ans = (ans + profits(n-group[i], newprofit, group, profit, i+1))%mod;
        }
        return memo[n][mprofit][i] = ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int i = group.size();
        memo.resize(n+1, vector<vector<int>>(minProfit+1, vector<int>(i, -1)));
        return profits(n, minProfit, group, profit, 0);
        
    }
};