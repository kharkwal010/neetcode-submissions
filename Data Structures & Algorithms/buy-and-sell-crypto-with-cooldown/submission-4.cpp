class Solution {
public:
    vector<vector<int>> memo;
    int profit(vector<int>& prices, bool buy, int i){
        if(i>=prices.size()) return 0;
        if(memo[i][buy]!=INT_MAX) return memo[i][buy];
        int leave = profit(prices, buy, i+1);
        int transact;
        if(buy) transact = profit(prices, !buy, i+1) - prices[i];
        else transact = profit(prices, !buy, i+2) + prices[i];
        memo[i][buy] = max(leave, transact);
        return memo[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2, INT_MAX));
        return profit(prices, true, 0);
    }
};
