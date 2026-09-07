class Solution {
public:
    vector<int> memo;
    int dp(int n){
        if(n==0) return 0;
        if(memo[n]!=-1) return memo[n];
        int ans = INT_MAX;
        long long i = 1;
        while(n>=i*i){
            ans = min(ans, 1 + dp(n - i*i));
            i++;
        }
        return memo[n] = ans;

    }
    int numSquares(int n) {
        memo.resize(n+1, -1);
        return dp(n);
    }
};