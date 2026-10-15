class Solution {
public:
    void gen(string& curr, vector<string>& strs, int m, int prev){
        if(m==0){
            strs.push_back(curr);
            return;
        }
        for(int i=0; i<3; i++){
            if(i==prev) continue;
            curr.push_back(i+'0');
            gen(curr, strs, m-1, i);
            curr.pop_back();
        }
        return;        
    }
    int memo[1001][48];
    int mod = 1e9+7;
    int color(int& m, int n, int prev, vector<string>& terms){
        if(n==0) return 1;
        if(memo[n][prev]!=-1) return memo[n][prev];
        long long ans = 0;
        for(int i=0; i<terms.size(); i++){
            bool use = true;
            for(int j=0; j<m; j++){
                if(terms[prev][j]==terms[i][j]){
                    use = false;
                    break;
                }
            }
            if(use) ans = (ans +  color(m, n-1, i, terms))%mod;
            
        }
        return memo[n][prev] = ans;
    }

    int colorTheGrid(int m, int n) {
        vector<string> terms;
        string curr = "";
        gen(curr, terms, m, 3);
        memset(memo, -1, sizeof(memo));
        long long ans = 0;
        for(int i=0; i<terms.size(); i++){
            ans = (ans + color(m, n-1, i, terms))%mod;
        }
        return ans;     
    }
    
};