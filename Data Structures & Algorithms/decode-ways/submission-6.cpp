class Solution {
public:
    unordered_map<int, int> memo;

    int dp(string &s, int i) {
        if (i == s.size()) return 1;            // reached end → 1 valid decoding
        if (s[i] == '0') return 0;              // invalid: cannot decode '0' alone
        if (memo.find(i) != memo.end()) return memo[i];

        int ways = dp(s, i + 1);                // decode one digit

        // decode two digits if valid (10–26)
        if (i + 1 < s.size()) {
            int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (two >= 10 && two <= 26) {
                ways += dp(s, i + 2);
            }
        }

        memo[i] = ways;
        return ways;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        return dp(s, 0);
    }
};
