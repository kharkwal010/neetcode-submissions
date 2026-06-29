class Solution {
public:
    vector<vector<int>> memo;
    int cost(int left, int right, vector<int>& cuts, int l, int r){
        if(l>r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int ans = INT_MAX;
        for(int i=l; i<=r; i++){
            ans = min(ans, cost(left, cuts[i], cuts, l, i-1) + right - left + cost(cuts[i], right, cuts, i+1, r));
        }
        memo[l][r] = ans;
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        memo.resize(c, vector<int>(c, -1));
        return cost(0, n, cuts, 0, c-1);
    }
};