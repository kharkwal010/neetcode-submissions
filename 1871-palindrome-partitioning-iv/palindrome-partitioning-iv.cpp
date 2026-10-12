class Solution {
public:
    vector<vector<bool>> pal;
    bool palin(string s, int i, int curr){
        if(i==s.size()) return false;
        if(curr==2){
           return pal[i][s.size()-1];
        }
        bool ans = false;
        for(int j=i; j<s.size(); j++){
            if(pal[i][j]) ans = ans || palin(s, j+1, curr+1);
        }
        return ans;
    }
    bool checkPartitioning(string s) {
        int n = s.size();
        pal.resize(n, vector<bool>(n, false));
        for(int i=0; i<s.size(); i++){
            pal[i][i] = true;
            if(i<n-1 && s[i]==s[i+1]) pal[i][i+1] = true;
        }
        for(int len = 2; len<s.size(); len++){
            for(int i=0; i<n-len; i++){
                int r = i+len;
                if(pal[i+1][r-1] && s[i]==s[r]) pal[i][r] = true;
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         cout<<i<<" "<<j<<" "<<pal[i][j]<<endl;
        //     }
        // }
        return palin(s, 0, 0);

        
    }
};