class Solution {
public:
    vector<long long> memo;
    long long dp(vector<int>& arr, int k, int i){
        if(i==arr.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int maxi = 0;
        long long ans = 0;
        for(int j=i; j<min((int)arr.size(), i+k); j++){
            maxi = max(maxi, arr[j]);
            ans = max(ans, maxi*(j-i+1) + dp(arr, k, j+1));
        }
        return memo[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
      memo.resize(n, -1);
      return dp(arr, k, 0);

    }
};