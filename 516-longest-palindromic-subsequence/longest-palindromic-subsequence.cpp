class Solution {
public:
    vector<vector<int>> memo;
    int dp(string& s, int l, int r){
        if(l==r) return 1;
        if(l>r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int ans = 0;
        if(s[l]==s[r]) ans = max(ans, 2 + dp(s, l+1, r-1));
        ans = max(ans, dp(s, l, r-1));
        ans = max(ans, dp(s, l+1, r));
        return memo[l][r] = ans;
        
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n, -1));
        return dp(s, 0, n-1);

    }
};