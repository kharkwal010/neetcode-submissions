class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> memo;
    int arrange(int n, int k){
        if(n==0 && k==0) return 1;
        if(n==0 || k==0) return 0;
        if(memo[n][k]!=-1) return memo[n][k];
        long long ans = 0;
        ans = (ans + 1LL*(n-1)*arrange(n-1, k))%mod;
        ans = (ans + arrange(n-1, k-1))%mod;
        return memo[n][k]=ans;
        
    }
    int rearrangeSticks(int n, int k) {
        memo.resize(n+1, vector<int>(k+1, -1));
        return arrange(n, k);
    }
};