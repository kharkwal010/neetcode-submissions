class Solution {
public:
    vector<vector<vector<int>>> memo;
    // pos, count of 1 seen till now, tight
    int dp(string& s, int i, bool tight, int count){
        if(i==s.size()) return count;
        if(memo[i][count][tight]!=-1) return memo[i][count][tight];
        int ub = (tight) ? s[i]-'0' : 9;
        int ans = 0;
        for(int j=0; j<=ub; j++){
            if(j==1) count++;
            ans += dp(s, i+1, (tight && j==ub), count);
            if(j==1) count--;
        }
        return memo[i][count][tight] = ans;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        int sz = s.size();
        memo.resize(sz, vector<vector<int>>(sz+1, vector<int>(2, -1)));
        return dp(s, 0, true, 0);
    }
};