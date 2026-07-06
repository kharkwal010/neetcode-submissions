class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<long long> prefix(prices.size()+1, 0);
        for(int i=0; i<prices.size(); i++){
            prefix[i+1] = prices[i] + prefix[i];
        }
       
        vector<long long> profit(prices.size()+1, 0);
        for(int i=0; i<prices.size(); i++){
            profit[i+1] = profit[i] + prices[i] * strategy[i];
        }
        long long ans = profit[prices.size()];
        long long maxdiff = INT_MIN;
        for(int i=k; i<profit.size(); i++){
            maxdiff = max(maxdiff, (prefix[i] - prefix[i-k/2]) - (profit[i] - profit[i-k]));
        }
        return max(ans, ans + maxdiff);

    }
};