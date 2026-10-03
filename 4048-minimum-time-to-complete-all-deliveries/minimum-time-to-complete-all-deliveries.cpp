class Solution {
public:
    bool check(vector<int>& d, vector<int>& r, long long time){
        long long t_eff = time - time / lcm(r[0], r[1]);
        if( (long long)d[0]+d[1]>t_eff) return false;
        long long t1 = time - time / r[0];
        if( (long long)d[0]>t1) return false;
        long long t2 = time - time / r[1];
        if( (long long)d[1]>t2) return false;
        return true;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long l = (long long)d[0] + d[1];
        long long ri = 2*l;
        long long ans = ri;
        while(l<=ri){
            long long m = (l+ri)/2;
            if(check(d, r, m)){
                ans = m;
                ri = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};