class Solution {
public:
    vector<long long> memo;
    long long dp(vector<vector<int>>& rides, int i){
        if(i==rides.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        long long ans = 0;
        ans = max(ans, dp(rides, i+1));
        int r = rides.size()-1;
        int l = i+1;
        int curr = rides[i][1];
        int val = rides[i][1] - rides[i][0] + rides[i][2];
        int nxt = r;
        if(rides[r][0]<curr) ans = max(ans, val + dp(rides, r+1));
        else{
            while(l<=r){
                int m = (l+r)/2;
                if(rides[m][0]>=curr){
                    nxt = m;
                    r = m - 1;
                }
                else l = m + 1;

            }
            ans = max(ans, val + dp(rides, nxt));
        }
        return memo[i] = ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int p = rides.size();
        memo.resize(p, -1);
        sort(rides.begin(), rides.end());
        return dp(rides, 0);
        
    }
};