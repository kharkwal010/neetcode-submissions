class Solution {
public:
    vector<vector<vector<int>>> memo;
    int stones(vector<int>& piles, int m, int i, bool alice){
        if(i==piles.size()) return 0;
        if(memo[i][m][alice]!=-1) return memo[i][m][alice];
        int res = (alice) ? 0 : INT_MAX;
        int ans = 0;
        for(int j=0; j<2*m && i+j<piles.size(); j++){
            ans = ans + piles[i+j];
            if(alice){                
                res = max(res, ans + stones(piles, max(m, j+1), i+j+1, !alice));
            }
            else res = min(res, stones(piles, max(m, j+1), i+j+1, !alice));
        }
        memo[i][m][alice] = res;
        return res;     

    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memo.resize(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return stones(piles, 1, 0, 1);
    }
};