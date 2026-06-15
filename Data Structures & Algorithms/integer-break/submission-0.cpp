class Solution {
public:
    unordered_map<int, int> memo;
    int prod(int n, int num){
        if(n==1) return 1;
        if(memo.find(n)!=memo.end()) return memo[n];
        int res = (n==num) ? 0 : n;
        for(int i=1; i<=n/2; i++){
            int ans = prod(i, num) * prod(n-i, num);
            res = max(ans, res);
        }
        memo[n]=res;
        return memo[n];

    }
    int integerBreak(int n) {
        return prod(n, n);
    }
};