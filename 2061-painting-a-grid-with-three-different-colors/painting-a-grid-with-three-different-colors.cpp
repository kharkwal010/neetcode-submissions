class Solution {
public:
    vector<string> comb;
    int mod = 1e9+7;
    void generate(int i, vector<char>& val, int& m, string curr, char prev){
        if(i==m){
            comb.push_back(curr);
            return;
        }
        for(int j=0; j<3; j++){
            if(val[j]==prev) continue;
            curr.push_back(val[j]);
            generate(i+1, val, m, curr, val[j]);
            curr.pop_back();
        }
        return;

    }

    vector<vector<int>> memo;
    int dp(int prev, int i, int& n, int& m){
        if(i==n) return 1;
        if(memo[prev][i]!=-1) return memo[prev][i];
        long long ans = 0;
        for(int k=0; k<comb.size(); k++){
            bool match = false;
            for(int j=0; j<m; j++){
                if(comb[prev][j]==comb[k][j]){
                    match = true;
                    break;
                }
            }
            if(!match) ans = (ans + dp(k, i+1, n, m))%mod;
        }
        return memo[prev][i] = ans;

    }
    int colorTheGrid(int m, int n) {
        vector<char> val = {'a', 'b', 'c'};
        generate(0, val, m, "", 'd');

        int c = comb.size();
        memo.resize(c, vector<int>(n, -1));
        long long ans = 0;
        for(int j=0; j<comb.size(); j++){
            ans = (ans + dp(j, 1, n, m))%mod;
        }
        return ans;        
    }
};