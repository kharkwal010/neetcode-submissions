class Solution {
public:
    unordered_map<int, int> memo;
    int comb(string s, int i){
        if(i==s.size()) return 1;
        else if(s[i]-'0'==0) return 0;
        if(memo.find(i)!=memo.end()) return memo[i];
        int one = comb(s, i+1);
        int two;
        if(i<s.size()-1 && stoi(s.substr(i,2))<=26) two = comb(s, i+2);
        memo[i] = one+two;
        return memo[i];

    }
    int numDecodings(string s) {
       return comb(s, 0);
    }
};
