class Solution {
public:
    vector<vector<int>> memo;
    int mod = 1e9 + 7;
    long long ways(int target, vector<vector<int>>& types, int i){
        if(target==0) return 1;
        if(i==types.size()) return 0;
        if(memo[target][i]!=-1) return memo[target][i];
        long long ans = 0;
        int marks = types[i][1];
        for(int j=0; j<=types[i][0]; j++){
            int tar = target - j*marks;
            if(tar<0) break;
            ans = (ans + ways(tar, types, i+1))%mod;
        }
        return memo[target][i] = ans;

    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memo.resize(target+1, vector<int>(types.size(), -1));
        return ways(target, types, 0);
    }
};