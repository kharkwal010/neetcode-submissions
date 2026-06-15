class Solution {
public:
    unordered_map<string, int> memo;
    int dp(string s, string t, int i, int j){
        if(j==t.size()) return 1;
        else if(i==s.size()) return 0;
        string key = to_string(i) + "," + to_string(j);
        if(memo.find(key)!=memo.end()) return memo[key];
        int leave = dp(s, t, i+1, j);
        int pick = 0;
        if(s[i]==t[j]) pick = dp(s, t, i+1, j+1);
        memo[key] = leave + pick;
        return memo[key];
    }
    int numDistinct(string s, string t) {
        if(t.size()>s.size()) return 0;
        return dp(s, t, 0, 0);
    }
};
