class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;        
        int ans = 0;
        int sell = 1;

        while(sell<prices.size()){
            if(prices[buy]>=prices[sell]){
                buy=sell;
                sell++;
            }
            else if(prices[buy]<prices[sell]){
                ans = max(ans, prices[sell]-prices[buy]);
                sell++;
            }

        }
        return ans;
    }
};
