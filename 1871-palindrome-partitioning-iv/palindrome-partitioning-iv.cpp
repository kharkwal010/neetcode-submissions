class Solution {
public:
    vector<vector<int>> palin;
    bool checkPartitioning(string s) {
        int n = s.size();
        palin.resize(n, vector<int>(n, false));
        for(int len = 1; len<=n; len++){
            for(int l=0; l<n-len+1; l++){
                int r = l+len-1;
                if(s[l]==s[r]){
                    if(l+1>r-1 || palin[l+1][r-1]) palin[l][r] = true;
                }
            }
        }
        for(int i=0; i<n-2; i++){
            if(palin[0][i]){
                for(int j=i+1; j<n-1; j++){
                    if(palin[i+1][j] && palin[j+1][n-1]) return true;
                }
            }
        }
        return false;
    }
};