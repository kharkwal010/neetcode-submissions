class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> digits;
    int inf = 1e5;
    int count(vector<int>& primes, int sum, int i){
        if(sum==0) return 0;
        if(i==primes.size()) return inf;
        if(digits[i][sum]!=-1) return digits[i][sum];
        int ans = inf;
        ans = min(ans, count(primes, sum, i+1));
        if(sum-primes[i]>=0) ans = min(ans, 1 + count(primes, sum-primes[i], i+1));
        return digits[i][sum] = ans;

    }
    int maxsum(vector<int>& primes, int s, int i){
        if(i==primes.size()) return 0;
        if(memo[i][s]!=-1) return memo[i][s];
        int sum = 0;
        sum = max(sum, maxsum(primes, s, i+1));
        if(primes[i]<=s) sum = max(sum, primes[i] + maxsum(primes, s-primes[i], i+1));
        return memo[i][s] = sum;
    }
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> primes;
        vector<bool> terms(n+1, true);
        for(int i=2; i<terms.size(); i++){
            if(!terms[i]) continue;
            primes.push_back(i);
            for(int j = i*i; j<terms.size(); j+=i){
                terms[j] = false;
            }
        }
        int p = primes.size();
        memo.assign(p, vector<int>(s+1, -1));
        int sum = maxsum(primes, s, 0);
        digits.assign(p, vector<int>(sum+1, -1));
        int cnt = count(primes, sum, 0);
        cout<<cnt<<endl;
        vector<int> ans;
        for(int i=0; i<primes.size(); i++){
            if(primes[i]>sum) continue;
            if(1 + count(primes, sum - primes[i], i+1)==cnt){
                ans.push_back(primes[i]);
                sum -= primes[i];
                cnt--;
            }
        }
        return ans;

    }
};