class Solution {
public:
    vector<vector<vector<long long>>> memo;
    long long profit(vector<int>& prices, int k, int i, int state){
        if(k==0) return 0;
        if(i==prices.size()){
            if(state==0) return 0;
            else return INT_MIN;
        }
        if(memo[i][k][state]!=LLONG_MIN) return memo[i][k][state];
        long long ans = INT_MIN;
        ans = max(ans, profit(prices, k, i+1, state));
        if(state==0){
            ans = max(ans, prices[i] + profit(prices, k, i+1, 1));
            ans = max(ans, -prices[i] + profit(prices, k, i+1, 2));
        }
        else if(state==1){
            ans = max(ans, -prices[i] + profit(prices, k-1, i+1, 0));
        }
        else ans = max(ans, prices[i] + profit(prices, k-1, i+1, 0));
        return memo[i][k][state] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        memo.assign(n, vector<vector<long long>>(k+1, vector<long long>(3, LLONG_MIN)));
        return profit(prices, k, 0, 0);
    }
};