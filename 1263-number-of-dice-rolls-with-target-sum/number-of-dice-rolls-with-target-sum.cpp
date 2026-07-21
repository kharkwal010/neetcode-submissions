class Solution {
public:
    vector<vector<int>> memo;
    int mod = 1e9+7;
    int ways(int n, int& k, int target){
        if(n==1){
            if(k>=target) return 1;
            return 0;
        }
        if(memo[n][target]!=-1) return memo[n][target];
        long long ans = 0;
        for(int i=1; i<=k; i++){
            if(i>=target) break;
            ans = (ans + (ways(n-1, k, target-i)))%mod;
        }
        return memo[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memo.resize(n+1, vector<int> (target+1, -1));
        return ways(n, k, target);

    }
};