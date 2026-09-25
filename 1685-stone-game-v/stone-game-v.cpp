class Solution {
public:
    vector<vector<int>> memo;
    int value(vector<int>& stone, int l, int r){
        if(l==r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int ans = 0;
        for(int i=l; i<r; i++){
            int left = stone[i] - stone[l-1];
            int right = stone[r] - stone[i];
            if(left<right) ans = max(ans, left + value(stone, l, i));
            else if(right<left) ans = max(ans, right + value(stone, i+1, r));
            else{
                ans = max(ans, max(left + value(stone, l, i), right + value(stone, i+1, r)));
            }
        }
        
        
        return memo[l][r] =  ans;

    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> stone(n+1, 0);
        for(int i=0; i<n; i++){
            stone[i+1] = stone[i] + stoneValue[i];
        }
        memo.resize(n+1, vector<int>(n+1, -1));
        return value(stone, 1, n);

    }
};