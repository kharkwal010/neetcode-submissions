class Solution {
public:
    int numberOfWays(string corridor) {
        int s = 0;
        for(char c: corridor){
            if(c=='S') s++;
        }
        if(s==0 || s%2==1) return 0;
        int mod = 1e9 + 7;
        int l = 0;
        int r = corridor.size()-1;
        long long ans = 1;
        while(corridor[l]=='P') l++;
        while(corridor[r]=='P') r--;

        // cout<<l<<" "<<r<<endl;
        s = 0;
        while(l<r){
            if(corridor[l]=='S') s++;
            if(s%2==0){
                int count = 1;
                l++;
                while(l<r && corridor[l]=='P'){
                    count++;
                    l++;
                }
                ans = ((ans)* count)%mod;
                l--;
            }
            l++;
        }
        return ans;
    }
};