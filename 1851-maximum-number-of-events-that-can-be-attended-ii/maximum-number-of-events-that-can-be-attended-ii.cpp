class Solution {
public:
    vector<vector<int>> memo;
     int value(vector<vector<int>>& events, int k, int i){
        if(i==events.size() || k==0) return 0;
        if(memo[i][k]!=-1) return memo[i][k];
        int ans = 0;
        ans = max(ans, value(events, k, i+1));
        int l = i+1;
        int r = events.size()-1;
        int target = events[i][1] + 1;
        // smallest number greater/ equal to target
        int next = r+1;
        while(l<=r){
            int m = (l+r)/2;
            if(events[m][0]<target) l = m+1;
            else{
                next = m;
                r = m-1;
            }
        }
        ans = max(ans, events[i][2] + value(events, k-1, next));
        return memo[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        memo.resize(n, vector<int>(k+1,-1));
        sort(events.begin(), events.end());
        return value(events, k, 0);        
    }
};