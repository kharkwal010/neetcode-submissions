class Solution {
public:
    unordered_map<int, int> memo;
    int decode(string s, int i){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(memo.count(i)) return memo[i];
        int ans=0;
        ans = ans + decode(s, i+1);
        int two = 100;
        if(i<s.size()-1) two = stoi(s.substr(i, 2));
        if(two<27) ans = ans + decode(s, i+2);
        memo[i]= ans;
        return memo[i];
        
    }
    int numDecodings(string s) {
        return decode(s, 0);
    }
};
