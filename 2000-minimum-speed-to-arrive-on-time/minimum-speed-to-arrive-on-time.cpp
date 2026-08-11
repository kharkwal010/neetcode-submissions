class Solution {
public:
    bool check(vector<int>& dist, double hour, int m){
        double ans = 0;
        int n = dist.size();
        for(int i=0; i<n-1; i++){
            ans += ceil((double)dist[i]/m);
        }
        ans += (double) dist[n-1]/m;
        return (ans<=hour);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<=n-1) return -1;
        int l = 1;
        int r = 1e7;
        int ans = l;
        while(l<=r){
            int m = (l+r) / 2;
            if(check(dist, hour, m)){
                ans = m;
                r = m-1;
            }
            else l=m+1;

        }
        return ans;
    }
};