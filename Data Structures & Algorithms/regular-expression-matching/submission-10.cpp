class Solution {
public:
    unordered_map<string, bool> memo;
    bool match(string s, string p, int i, int j){
        if(j==p.size()){
            if(i==s.size()) return true;
            else return false;
        }
        string key = to_string(i) + "," + to_string(j);
        if(memo.find(key)!=memo.end()) return memo[key];
        bool ans = false;
        bool dot = (p[j]=='.');
        bool star = (j<p.size()-1 && p[j+1]=='*');
        
        if(star){
            ans = ans || match(s, p, i, j+2);
            if(!dot){
                while(i<s.size() && s[i] == p[j]){
                    ans = ans || match(s, p, i+1, j+2);
                    i++;
                }
            }
            else{
                while(i<s.size()){
                    ans = ans || match(s, p, i+1, j+2);
                    i++;
                }
            }
        }
        else if(dot) ans = ans || match(s, p, i+1, j+1);
        else if(i<s.size() && s[i]==p[j]) ans = ans || match(s, p, i+1, j+1);
        memo[key] = ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }
};
