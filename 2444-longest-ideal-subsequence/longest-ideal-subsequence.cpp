class Solution {
public:
    vector<vector<int>> memo;
    int sub(string& s, int& k, int prev, int i){
        if(i==s.size()) return 0;
        if(memo[i][prev]!=-1) return memo[i][prev];
        int ans = 0;
        int leave = sub(s, k, prev, i+1);
        int pick = 0;
        if(abs(s[i]-'a'-prev)<=k) pick = 1 + sub(s, k, s[i]-'a', i+1);
        memo[i][prev] = max(leave, pick);
        return memo[i][prev];

    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        memo.resize(n, vector<int>(26, -1));
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans = max(ans, sub(s, k, s[i]-'a', i+1));
        }
        return ans + 1;
    }
};