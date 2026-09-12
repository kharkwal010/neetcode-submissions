class Solution {
public:

    /*  0 - free
        1 - long
        2 - short
    */
     
    vector<vector<vector<long long>>> memo;
    long long profit(vector<int>& prices, int i, int k, int state){
        if(i==prices.size()){
            if(state==0) return 0;
            else return INT_MIN;
        }
        if(k==0) return 0;
        if(memo[i][k][state]!=INT_MIN) return memo[i][k][state];
        long long ans = INT_MIN;
        ans = max(ans, profit(prices, i+1, k, state));
        if(state==0){
            ans = max(ans, -prices[i] + profit(prices, i+1, k, 1));
            ans = max(ans, prices[i] + profit(prices, i+1, k, 2));
        }
        else if(state==1){
            ans = max(ans, prices[i] + profit(prices, i+1, k-1, 0));
        }
        else ans = max(ans, -prices[i] + profit(prices, i+1, k-1, 0));
        return memo[i][k][state] = ans;

    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        memo.resize(n, vector<vector<long long>>(k+1, vector<long long>(3, INT_MIN)));
        return profit(prices, 0, k, 0);
    }
};