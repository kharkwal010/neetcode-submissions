class Solution {
public:
    vector<vector<int>> dp;
    int count(string& s, int l, int r){
        int ans = 0;
        while(l<r){
            if(s[l]!=s[r]){
                ans++;
            }
            l++;
            r--;
        }
        return ans;
    }

    vector<vector<int>> memo;
    int inf = 1000;
    int palin(string& s, int k, int i){
        if(k==0) return (i==s.size()) ? 0 : inf;
        if(s.size()-i==k) return 0;
        if(s.size()-i<k) return inf;
        if(memo[i][k]!=-1) return memo[i][k];
        int ans = INT_MAX;
        for(int j=i; j<=s.size()-k; j++){
            ans = min(ans, dp[i][j] + palin(s, k-1, j+1));
        }
        return memo[i][k] = ans;
    }


    int palindromePartition(string s, int k) {
        int n = s.size();
        dp.resize(n, vector<int>(n, 0));
        for(int i=0; i<s.size(); i++){
            for(int j=s.size()-1; j>=i; j--){
                dp[i][j] = count(s, i, j);
            }
        }

        memo.resize(n, vector<int>(k+1, -1));
        return palin(s, k, 0);


    }
};