class Solution {
public:
    /*A:0 P:1 L:2*/
    int memo[100001][3][2][2];
    int mod = 1e9 + 7;
    int check(int n, int prev, bool l, bool a){
        if(n==0) return 1;
        if(memo[n][prev][l][a]!=-1) return memo[n][prev][l][a];
        long long ans = 0;
        ans = (ans + check(n-1, 1, true, a))%mod;
        if(a) ans = (ans + check(n-1, 0, true, false))%mod;
        if(l){
            if(prev==2) ans = (ans + check(n-1, 2, false, a))%mod;
            else ans = (ans + check(n-1, 2, true, a))%mod;
        }
        return memo[n][prev][l][a] = ans;
        
    }
    int checkRecord(int n) {
        memset(memo, -1, sizeof(memo));
        long long ans = 0;
        ans = (ans + check(n-1, 1, true, true))%mod;
        ans = (ans + check(n-1, 0, true, false))%mod;
        ans = (ans + check(n-1, 2, true, true))%mod;
        return ans;
    }
};