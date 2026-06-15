class Solution {
public:
    unordered_map<int, double> memo;
    double myPow(double x, int n) {
        if(n==0) return 1;
        if (n==1) return x;
        if(n==-1) return 1/x;
        if(memo.count(n)) return memo[n];
        int p = n/2;
        memo[n] = myPow(x,n/2)*myPow(x,n-p);
        return memo[n];
    }
};
