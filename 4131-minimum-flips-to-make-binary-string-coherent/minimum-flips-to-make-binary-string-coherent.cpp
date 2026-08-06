class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int one = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') one++;
        }
        int res1 = n - one;
        int res2 = max(0, one - 1);
        int res3 = max(0, one - (s[0]-'0') - (s[n-1]-'0'));
        return min({res1, res2, res3});
    }
};