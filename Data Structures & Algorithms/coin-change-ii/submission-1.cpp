class Solution {
public:
    vector<vector<int>> memo;
    int dfs(int amount, vector<int> coins, int i){
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        if (memo[i][amount]!= -1){
            return memo[i][amount];
        }
        int sum = 0;
        for (int j = i; j<coins.size(); j++){
            sum = sum + dfs(amount - coins[j], coins, j);
        }
        memo[i][amount] = sum;
        return memo[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        memo = vector<vector<int>>(coins.size()+1, vector<int>(amount + 1, -1));
        return dfs(amount, coins, 0);
    }
};
