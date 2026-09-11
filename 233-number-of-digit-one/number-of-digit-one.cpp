class Solution {
public:
    vector<vector<vector<int>>> memo;
    int dp(string& s, int i, int count, bool tight){
        if(i==s.size()) return count;
        if(memo[i][count][tight]!=-1) return memo[i][count][tight];
        int ub = (tight) ? s[i]-'0' : 9;
        int n = 0;
        for(int j=0; j<=ub; j++){
            bool one = (j==1);
            n += dp(s, i+1, count + one, tight && j==ub);
        }
        return memo[i][count][tight] = n;
    }
    int countDigitOne(int n) {
        string term = to_string(n);
        int y = term.size();
        memo.resize(y, vector<vector<int>>(y, vector<int>(2, -1)));
        return dp(term, 0, 0, true);
    }
};