class Solution {
public:
    vector<vector<int>> memo;
    int numbers(vector<char>& digits, string& n, bool tight, int i){
        if(i==n.size()) return 1;
        if(memo[i][tight]!=-1) return memo[i][tight];
        char high = n[i];
        if(!tight) high = '9';
        int ans = 0;
        for(char c: digits){
            if(c>high) break;
            ans += numbers(digits, n, (tight && c==high), i+1);
        }
        return memo[i][tight] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        memo.resize(num.size(), vector<int>(2, -1));
        vector<char> digit;
        for(auto d: digits) digit.push_back(d[0]);
        int ans = numbers(digit, num, true, 0);
        for(int i=1; i<num.size(); i++){
            ans += numbers(digit, num, false, i);
        }
        return ans;

    }
};