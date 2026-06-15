class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n, 1);
        int count = 0;
        if(n==0 || n==1) return 0;
        primes[0] = 0;
        primes[1] = 0;
        for(int i=2; i<n; i++){
            if(primes[i]==0) continue;
            count++;
            for(long long j = (long long)i*i; j<n; j+=i){
                primes[j]=0;
            }
        }
        return count;

    }
};