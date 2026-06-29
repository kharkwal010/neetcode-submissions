class Solution {
public:
    unordered_map<int, long long> memo;
    long long count(long long n){
        if(n==1) return 1;
        int mod = 1e9 + 7;
        // if(memo.count(n)) return memo[n];
        return ((2*n-1)*n*count(n-1))%mod;
        
    }

    int countOrders(int n) {
        return count(n);
    }
};