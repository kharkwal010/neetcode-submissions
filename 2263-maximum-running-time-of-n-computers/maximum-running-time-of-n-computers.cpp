class Solution {
public:
    bool check(vector<int>& batteries, int n, long long time, long long extra){
        for(int i=0; i<n; i++){
            if(time-batteries[i]>extra) return false;
            long long given = max(1LL*0, time-batteries[i]);
            extra -= given;
        }
        return true;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long extra = 0;
        sort(batteries.rbegin(), batteries.rend());
        for(int i=n; i<batteries.size(); i++) extra += batteries[i];
        long long l = 0;
        long long ans = 0;
        long long sum = extra;
        // cout<<extra<<endl;
        for(int i=0; i<n; i++) sum += batteries[i];
        long long r = sum / n;
        while(l<=r){
            long long m = (l+r)/2;
            if(check(batteries, n, m, extra)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;

    }
};