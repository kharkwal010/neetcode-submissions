class Solution {
public:
    unordered_map<int, int> memo;

    int dp(string &s, int i) {
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(memo.find(i)!=memo.end()){
            return memo[i];
        }
        int two;
        if(i<s.size()-1){
            two = stoi(s.substr(i,2));
        }
        int ways = 0;
        if(two && two>=10 && two<=26){
            ways = ways + dp(s, i+1) + dp(s, i+2);
        }
        else{
            ways = ways + dp(s, i+1);
        }
        memo[i]=ways;
        return memo[i];
    }

    int numDecodings(string s) {
        return dp(s, 0);
    }
};
