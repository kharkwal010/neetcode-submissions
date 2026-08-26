class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int one = 0;
        for(char c: s) if(c=='1') one++;
        bool two = false;
        if(s[0]=='1' && s[n-1]=='1') two = true;
        if(one==0 || one==n) return 0;
        int ans1 = n - one;
        int extra = (two) ? 2 : 1;
        int ans2 = one - extra;
        return min(ans1, ans2);

    }
};