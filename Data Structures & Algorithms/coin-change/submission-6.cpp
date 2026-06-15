class Solution {
public:
    unordered_map<int, int> memo;
    int coin(vector<int> coins, int amount){
        if (amount == 0){
            return 0;
        }
        if (memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        int res = INT_MAX;
        for (int i=0; i<coins.size(); i++){
            if (amount - coins[i] >= 0){
                int result  = coin(coins, amount - coins[i]);
                if (result!=INT_MAX){
                    res = min (res , 1+result);
                }
            }
        }
        memo[amount]=res;
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
       int ans = coin(coins, amount);
       if (ans == INT_MAX){
        return -1;
       }
       return ans;
    }
};
