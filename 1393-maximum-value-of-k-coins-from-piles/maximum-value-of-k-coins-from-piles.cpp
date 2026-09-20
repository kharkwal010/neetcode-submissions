class Solution {
public:
   vector<vector<int>> memo;
   int coins(vector<vector<int>>& piles, int k, int i){
        if(i==piles.size() || k==0) return 0;
        if(memo[i][k] !=-1) return memo[i][k];
        int ans = 0;
        ans = max(ans, coins(piles, k, i+1));
        int coin = 0;
        int sum = 0;
        for(int ele: piles[i]){
            if(coin==k) break;
            coin++;
            sum += ele;
            ans = max(ans, sum + coins(piles, k-coin, i+1));            
        }
        return memo[i][k] = ans;


   }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memo.assign(n, vector<int>(k+1, -1));
        return coins(piles, k, 0);
    }
};