class Solution {
public:
    vector<vector<int>> memo;
    int mod;
    int ways(int s, int& r, int i){
        if(s==0){
            if(i==0) return 1;
            return 0;
        }
        if(memo[s][i]!=-1) return memo[s][i];
        long long count = 0;
        if(i>0) count = (count + ways(s-1, r, i-1))%mod;
        if(i<r) count = (count + ways(s-1, r, i+1))%mod;
        count = (count + ways(s-1, r, i))%mod;
        return memo[s][i]=count;
    }
    int numWays(int steps, int arrLen) {
        int r = min(steps/2, arrLen-1);
        mod = 1e9 + 7;
        memo.resize(steps+1, vector<int>(r+1, -1));
        return ways(steps, r, 0);
        
    }
};