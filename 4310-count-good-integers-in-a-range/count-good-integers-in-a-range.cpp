class Solution {
public:
    vector<vector<vector<long long>>> memo;
    // (curr, prev, tight);
    long long dp(string& s, int i, int prev, bool tight, int& k){
        if(i==s.size()) return 1;
        if(memo[i][prev][tight]!=-1) return memo[i][prev][tight];
        long long ans = 0;
        int lb = (prev==10) ? 0 : max(0, prev-k);
        int ub = (prev==10) ? 9 : min(9, prev+k);
        if(tight) ub = min(s[i]-'0', ub);

        for(int j=lb; j<=ub; j++){
            int n_prev = (prev==10 && j==0) ? 10 : j;
            ans += dp(s, i+1, n_prev, (tight && j==(s[i]-'0')), k);
        }
        return memo[i][prev][tight] = ans;
    }
    long long terms(string& s, int& k){
        memo.assign(s.size(), vector<vector<long long>>(11, vector<long long>(2, -1)));
        return dp(s, 0, 10, true, k);
    }
    long long goodIntegers(long long l, long long r, int k) {
        string s = to_string(r);
        long long right = terms(s, k);
        s = to_string(l-1);
        long long left = terms(s, k);
        return right - left;       

    }
};