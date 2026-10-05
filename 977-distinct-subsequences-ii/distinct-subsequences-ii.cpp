class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9+7;
        int n = s.size();
        vector<int> terms(n+1);
        unordered_map<char, int> prev;
        terms[0] = 1;
        for(int i=0; i<n; i++){
            long long val =  (terms[i]*2LL);
            if(prev.count(s[i])){
                int j = prev[s[i]];
                val = val - terms[j];
            }
            terms[i+1] = (val%mod + mod) %mod;
            prev[s[i]] = i;
        }
        if(terms[n]==0) return mod - 1;
        return terms[n]-1;

    }
};