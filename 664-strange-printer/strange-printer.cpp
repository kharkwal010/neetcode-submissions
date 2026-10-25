class Solution {
public:
    vector<vector<int>> memo;
    int count(string& s, int l, int r){
        if(l>r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int ans = INT_MAX;
        char c = s[l];
        int i = l;
        while(i<=r && s[i]==c){
            i++;
        }
        int j = i;
        ans = min(ans, 1 + count(s, i, r));
        while(i<=r){
            if(s[i]==c) ans = min(ans, count(s, j, i-1) + count(s, i, r));
            i++;
        } 
        
        return memo[l][r] = ans;

    }
    int strangePrinter(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n, -1));
        return count(s, 0, s.size()-1);
    }
};