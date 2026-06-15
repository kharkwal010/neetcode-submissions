class Solution {
public:
    vector<vector<int>> memo;
    int dp(string s, string t, int i, int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(memo[i][j]!=INT_MAX) return memo[i][j];
        int ans = 0;
        ans = ans + dp(s, t, i+1, j);
        if(s[i]==t[j]) ans = ans + dp(s, t, i+1, j+1);
        memo[i][j] = ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        memo.resize(s.size()+1, vector<int>(t.size(), INT_MAX));
        if(s.size()<t.size()) return 0;
        return dp(s, t, 0, 0);
        
    }
};
