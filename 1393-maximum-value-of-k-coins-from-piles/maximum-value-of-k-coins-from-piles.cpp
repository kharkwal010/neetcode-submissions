class Solution {
public:
    vector<vector<int>> memo;
    int coins(vector<vector<int>>& piles, int k, int i){
        if(k==0 || i==piles.size()) return 0;
        if(memo[i][k]!=-1) return memo[i][k];
        int ans = 0;
        ans = max(ans, coins(piles, k, i+1));
        int last = min((int)piles[i].size(), k);
        int sum = 0;
        for(int j=0; j<last; j++){
            sum += piles[i][j];
            ans = max(ans, sum + coins(piles, k-j-1, i+1));
        }
        return memo[i][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memo.resize(n, vector<int>(k+1, -1));
        return coins(piles, k, 0);
    }
};