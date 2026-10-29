class Solution {
public:
    vector<vector<int>> memo;
    int mod = 1e9+7;
    int music(int n, int old, int& goal, int i, int& k){
        if(i==goal){
            if(old==n) return 1;
            return 0;
        }
        if(memo[i][old]!=-1) return memo[i][old];
        long long songs = 0;
        if(old!=n) songs = (songs + 1LL* (n-old) * music(n, old+1, goal, i+1, k))%mod;
        if(old>k) songs = (songs + 1LL * (old - k) * music(n, old, goal, i+1, k))%mod;
        return memo[i][old] = songs;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memo.resize(goal, vector<int>(n+1, -1));
        return music(n, 0, goal, 0, k);
    }
};