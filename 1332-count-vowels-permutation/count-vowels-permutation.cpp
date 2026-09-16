class Solution {
public:
    unordered_map<int, vector<int>> next;
    vector<vector<int>> memo;
    int mod;

    long long count(int n, int i){
        if(n==1) return 1;
        if(memo[n][i]!=-1) return memo[n][i];
        long long ans = 0;
        for(int nei: next[i]){
            ans = (ans + count(n-1, nei))%mod;
        }
        return memo[n][i]= ans;
    }

    int countVowelPermutation(int n) {
        next[0].push_back(1);
        next[1] = {0, 2};
        next[2] = {0, 1, 4, 3};
        next[3] = {2, 4};
        next[4].push_back(0);
        mod = 1e9+7;
        memo.resize(n+1, vector<int>(5, -1));
        long long ans = 0;
        for(int i=0; i<5; i++){
            // cout<<count(n, i)<<endl;
            ans = (ans + count(n, i))%mod;
        } 

        return ans;
        
        

    }
};