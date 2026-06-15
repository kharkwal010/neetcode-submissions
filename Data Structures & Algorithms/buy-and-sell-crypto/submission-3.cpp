class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell = 1;
        int size = prices.size();
        int profit=0;
        while (buy<size && sell<size){
            while(prices[sell]>prices[buy] &&  sell<size){
            if(profit<prices[sell]-prices[buy]){
                profit = prices[sell]-prices[buy];
            }
                sell++;
            }
                buy=sell;
                sell= buy+1;
            
        }
        return profit;
    }
};
