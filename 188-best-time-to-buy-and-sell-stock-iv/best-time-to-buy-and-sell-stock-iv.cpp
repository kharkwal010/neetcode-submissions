class Solution {
public:
    vector<vector<int>> memo;
    int profit(vector<int>& prices, int i, int k){
        if(k==0 || i==prices.size()) return 0;
        if(memo[i][k]!=INT_MIN) return memo[i][k];
        int ans = 0;
        if(k%2==0) ans = max(ans, -prices[i] + profit(prices, i+1, k-1));
        else ans = max(ans, prices[i] + profit(prices, i+1, k-1));
        ans = max(ans, profit(prices, i+1, k));
        return memo[i][k] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2*k+1, INT_MIN));
        return profit(prices, 0, 2*k);

    }
};