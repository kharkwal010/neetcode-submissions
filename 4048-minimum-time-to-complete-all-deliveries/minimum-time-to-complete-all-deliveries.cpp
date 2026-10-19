class Solution {
public:
    bool check(vector<int>& d, vector<int>& r, long long& lcm, long long m){
        long long extra = m / lcm;
        if(1LL* d[0] + d[1] > m - extra) return false;
        if(d[0]>m-m/r[0]) return false;
        if(d[1]>m-m/r[1]) return false;
        return true;
    }
    long long minimumTime(vector<int>& d, vector<int>& ri) {
        long long l = 1LL*d[0] + d[1];
        long long mul = lcm(ri[0], ri[1]);
        long long r = 2*l;
        long long ans = r;
        while(l<=r){
            long long m = (l+r)/2;
            cout<<m<<endl;
            if(check(d, ri, mul, m)){
                ans = m;
                r = m-1;
            }
            
            else l = m +1;
        }
        return ans;

    }
};