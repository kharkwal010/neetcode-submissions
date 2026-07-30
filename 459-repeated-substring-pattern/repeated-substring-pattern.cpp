class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0;
        for(int i=1; i<n; i++){
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
            }
            else{
                if(len==0) lps[i] = 0;
                else{
                    len = lps[len-1];
                    i--;
                }
            }
        }
        while(len>0){
            if(n%len==0){
                break;
            }
            else len = lps[len-1];
        }
        if(len==0) return false;
        string sub = s.substr(0, len);
        int mul = n/len;
        string new_s;
        while(mul>0){
            new_s += sub;
            mul--;
        }
        if(new_s==s) return true;
        return false;

    }
};