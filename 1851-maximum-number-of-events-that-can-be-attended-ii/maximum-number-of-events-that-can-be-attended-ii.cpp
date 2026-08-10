class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<vector<int>>& events, int k, int i){
        if(i==events.size() || k==0) return 0;
        if(memo[i][k]!=-1) return memo[i][k];
        int next = events[i][1] + 1;
        // cout<<i<<" "<<next<<endl;
        int l = i+1;
        int r = events.size()-1;
        int ans = r+1;
        while(l<=r){
            int m = (l+r) / 2;
            if(events[m][0]>=next){
                // cout<<"jeal"<<endl;
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        // cout<<next<<" "<<ans<<endl;
        int skip = solve(events, k, i+1);
        int take = events[i][2] + solve(events, k-1, ans);
        return memo[i][k] = max(take, skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        memo.resize(n, vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return solve(events, k, 0);
    }
};