class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int mismatch = 0;
        int one = 0;
        for(int i=0; i<t.size(); i++){
            if(s[i]!=t[i]){
                mismatch++;
                if(s[i]=='1') one++;
            }
        }
        if(mismatch==0) return 0;
        long long ans = 0;
        long long fc = 2*flipCost;
        long long sc = swapCost;
        if(fc<=sc) return (long long)mismatch * flipCost;
        int ns = min(mismatch-one, one);
        mismatch -= 2*ns;
        ans = sc * ns;
        long long cs = crossCost + swapCost;
        if(fc<=cs) ans += (long long)flipCost * mismatch;
        else{
            int nc = mismatch / 2;
            ans += cs * nc;
            if(mismatch%2!=0) ans += flipCost;
        }
        return ans;

    }
};