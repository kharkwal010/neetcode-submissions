class Solution {
public:
    vector<vector<int>> memo;
    int mod = 1e9+7;
    int die(vector<int>& rollMax, int n, int prev){
        // cout<<n<<" "<<prev<<endl;
        if(n==0) return 1;
        if(memo[n][prev]!=-1) return memo[n][prev];
        long long ans = 0;
        for(int i=0; i<6; i++){
            if(i==prev){
                continue;
            }
            int curr = min(n, rollMax[i]);
            for(int j=1; j<=curr; j++){
                ans = (ans + die(rollMax, n-j, i))%mod;
            }
        }
        return memo[n][prev] = ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memo.resize(n+1, vector<int>(7, -1));
        return die(rollMax, n, 6);

    }
};