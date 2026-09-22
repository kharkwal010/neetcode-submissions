class Solution {
public:
    vector<int> memo;
    int mod = 1e9 + 7;
    long long solve(int n, vector<int>& prev){
        if(n==0) return 1;
        if(memo[n]!=-1) return memo[n];
        long long total = 0;
        total = 2*solve(n-1, prev)%mod;
        if(prev[n-1]!=-1){
            total = (total - solve(prev[n-1], prev) + mod)% mod;
        }
        return memo[n] = total;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> prev(n, -1);
        vector<int> seen(26, -1);
        for(int i=0; i<n; i++){
            int j = s[i]-'a';
            prev[i] = seen[j];
            seen[j] = i;
        }
        memo.resize(n+1, -1);
        return (solve(n, prev) - 1 + mod) % mod;
    }
};