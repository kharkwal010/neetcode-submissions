class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        vector<int> suffix(t.size(), 0);
        vector<int> prefix(t.size(), 0);
        int n = s.size();
        int term = 0;
        for(int i=0; i<t.size(); i++){
            if(term<n && s[term]==t[i]) term++;
            prefix[i] = term;
        }
        term = 0;
        for(int i=t.size()-1; i>=0; i--){
            if(n-term-1 >= 0 && s[n-1-term]==t[i]) term++;
            suffix[i] = term;
        }
        for(int i=0; i<t.size(); i++){
            int prev = (i>0) ? prefix[i-1] : 0;
            int next = (i==t.size()-1) ? 0 : suffix[i+1];
            if(prev+next+1>=n) return true;
        }
        return false;
    }
};