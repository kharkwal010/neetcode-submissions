class Solution {
public:
    unordered_map<int, int> memo;
    int convert(int n){
        if(n==1) return 0;
        if(memo.count(n)) return memo[n];
        int ans = INT_MAX;
        if(n%2==0) ans = min(ans, 1 + convert(n/2));
        else ans = min(ans,2 + min(convert(n/2+1), convert(n/2)));
        return memo[n] = ans;
    }
    int integerReplacement(int n) {
        return convert(n);
    }
};