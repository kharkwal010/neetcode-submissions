class Solution {
public:
    vector<vector<vector<int>>> memo;
    int stone(vector<int>& piles, int j, int m, bool alice){
        if(j==piles.size()) return 0;
        if(memo[j][m][alice]!=-1) return memo[j][m][alice];
        int terms = 0;
        int ans = (alice) ? 0: INT_MAX;
        for(int i=j; i<2*m+j ; i++){
            if(i==piles.size()) break;
            terms += piles[i];
            if(alice) ans = max(ans, terms + stone(piles, i+1, max(m, i-j+1), !alice));
            else ans = min(ans, stone(piles, i+1, max(i-j+1, m), !alice));          
        }
        memo[j][m][alice] = ans;
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        memo.resize(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(2,-1)));
        return stone(piles, 0, 1, true);
    }
};