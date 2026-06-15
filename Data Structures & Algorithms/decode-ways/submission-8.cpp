class Solution {
public:
    unordered_map<int, int> memo;
    int comb(string s, int i){
        if(i>=s.size()){
            return 1;
        }
        if(memo.find(i)!=memo.end()){
            return memo[i];
        }
        if(s[i]=='0'){
            return 0;
        }
        int ans = 0;
        int two= stoi(s.substr(i,2));
        if(two>=10 && two<=26){
            ans = ans + comb(s, i+2) + comb(s, i+1);
        }
        
        else ans = ans + comb(s, i+1);
        memo[i]= ans;
        return memo[i];
    }
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        return comb(s,0);
    }
};
