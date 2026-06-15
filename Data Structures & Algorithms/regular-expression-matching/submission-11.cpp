class Solution {
public:
    vector<vector<int>> memo;
    bool match(string s, string p, int i, int j){
        if(j==p.size()){
            if(i==s.size()) return true;
            return false;
        }
        if(memo[i][j]!=-1) return memo[i][j];
        bool ans = false;
        if(i==s.size()){
            if(j<p.size()-1 && p[j+1]=='*') ans = ans || match(s, p, i, j+2);
            else return false;
        }
        bool isdot = false;
        bool star = false;
        if(p[j]=='.') isdot = true;
        if(j<p.size()-1 && p[j+1]=='*') star = true;
        if(star && isdot){
            for(int a=i; a<=s.size(); a++){
                ans = ans || match(s, p, a, j+2);
            }
        }
        else if(isdot){
            ans = ans || match(s, p, i+1, j+1);
        }
        else if(star){
            ans = ans || match(s, p, i, j+2);
            for(int a=i; a<s.size(); a++){
                if(s[a]==p[j]) ans = ans || match(s, p, a+1, j+2);
                else break;
            }
        }
        else{
            if(s[i]==p[j]) ans = ans || match(s, p, i+1, j+1);
        }
        memo[i][j] = ans;
        return ans;

    }
    bool isMatch(string s, string p) {
        memo.resize(s.size()+1, vector<int>(p.size()+1, -1));
        return match(s, p, 0, 0);
    }
};
