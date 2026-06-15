class Solution {
public:
    unordered_map<int, double> memo;
    double pow(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        if(memo.find(n)!=memo.end()) return memo[n];
        int p = n/2;
        memo[n] = pow(x, p) * pow(x, n-p);
        return memo[n];

    }
    double myPow(double x, int n) {
        if(n<0) return 1/pow(x, abs(n));
        return pow(x, n);
    }
};
