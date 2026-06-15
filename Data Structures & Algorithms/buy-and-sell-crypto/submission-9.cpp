class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]<prices[buy]){
                buy=i;
            }
            else{
                ans = max(prices[i]-prices[buy], ans);
            }
        }
        return ans;
    }
};
